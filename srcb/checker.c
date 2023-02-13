/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:46:59 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/13 14:36:01 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\r' || c == '\f' || c == '\v'
		|| c == '\t' || c == '\n')
		return (2);
	return (0);
}

void	check_stack(t_stack **a, char *line)
{
	t_stack	*b;

	b = NULL;
	while (line)
	{
		if (ft_strlen(line) < 3 && ft_strlen(line) > 4)
			stack_error(a, line, -1);
		if (ft_strncmp(line, "pa\n", 3) && ft_strncmp(line, "pb\n", 3)
			&& ft_strncmp(line, "sa\n", 3) && ft_strncmp(line, "sb\n", 3)
			&& ft_strncmp(line, "ra\n", 3) && ft_strncmp(line, "rb\n", 3)
			&& ft_strncmp(line, "rra\n", 4) && ft_strncmp(line, "rrb\n", 4)
			&& ft_strncmp(line, "rr\n", 3) && ft_strncmp(line, "rrr\n", 4)
			&& ft_strncmp(line, "ss\n", 3))
			stack_error(a, line, -1);
		check_result(a, &b, line);
		line = get_next_line(0);
	}
	if (is_sorted(*a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(line);
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
		stack_error(0, 0, 0);
	temp = *a;
	i = flag;
	while (arr[++i])
	{
		temp->num = ft_atoi(arr[i]);
		temp->chunk = 0;
		temp = temp->next;
	}
	if (flag == -1)
		free_arr(arr);
	check_stack(a, get_next_line(0));
	free_stack(a);
}

int	format_check(char **arr, int flag)
{
	int	i;
	int	j;

	i = flag;
	if (!arr[flag + 1] || !arr[flag + 1][0])
		format_error(arr, flag);
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
	int		i;

	arr = 0;
	i = -1;
	if (argc == 2 && !argv[1][0])
		return (0);
	while (argc == 2 && ft_isspace(argv[1][++i]))
		if (ft_isspace(argv[1][i]) == 2)
			format_error(0, 0);
	if (argc == 2 && !argv[1][i])
		format_error(0, 0);
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			format_check(0, 0);
		if (format_check(arr, -1))
			get_stack(arr, -1);
	}
	else if (argc > 2 && format_check(argv, 0))
		get_stack(argv, 0);
	return (0);
}
