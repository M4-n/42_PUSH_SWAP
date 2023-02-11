/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:18:32 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 15:22:48 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\f' || c == '\r' || c == '\v');
}

void	get_stack(char **arr, int flag)
{
	t_stack	**a;
	t_stack	*temp;
	int		i;
	int		len;

	i = flag;
	len = 0;
	while (arr[++i])
		len++;
	a = stack_init(len);
	if (!a)
		stack_error();
	temp = *a;
	i = flag;
	while (arr[++i])
	{
		temp->num = ft_atoi(arr[i]);
		temp = temp->next;
	}
	quick_sort_arr(arr, flag + 1, len, -1);
	parse_chunk(a, arr, len, flag + 1);
	if (flag == -1)
		free_arr(arr);
	sort_stack(a, len);
	free_stack(a);
}

int	format_check(char **arr, int flag)
{
	int	i;
	int	j;

	i = flag;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if ((j == 0 && (arr[i][j] != '-' && !ft_isdigit(arr[i][j])))
			|| (j != 0 && !ft_isdigit(arr[i][j])))
				format_error(arr, flag);
			if (j == 0 && arr[i][j] == '-' && ft_strlen(arr[i]) == 1)
				format_error(arr, flag);
		}
		if (ft_atol(arr[i]) < INT_MIN || INT_MAX < ft_atol(arr[i]))
			format_error(arr, flag);
	}
	if (is_dup(arr, flag))
		format_error(arr, flag);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**arr;

	arr = 0;
	if (argc == 2 && !argv[1][0])
		return (0);
	if (argc == 2 && ft_isspace(argv[1][0]))
		format_error(0, 0);
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (0);
		if (format_check(arr, -1))
			get_stack(arr, -1);
	}
	else if (argc > 2 && format_check(argv, 0))
		get_stack(argv, 0);
	return (0);
}
