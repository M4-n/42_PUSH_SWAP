/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 08:42:44 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 12:46:37 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

char	*ft_getline(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && (s[i] != '\n'))
		i++;
	if (s[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] != '\n'))
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_readline(int fd, char *str)
{
	char	*buffer;
	int		status;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	status = 1;
	while ((!gnlstrchr(str, '\n')) && status != 0)
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (status == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[status] = '\0';
		str = gnlstrjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str_fromline;
	static char	*str_fromread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_fromread = ft_readline(fd, str_fromread);
	if (!str_fromread)
		return (NULL);
	str_fromline = ft_getline(str_fromread);
	str_fromread = remove_prev_line(str_fromread);
	return (str_fromline);
}
