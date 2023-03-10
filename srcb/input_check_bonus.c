/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:57:43 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 13:00:21 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	is_sorted(t_stack *s)
{
	t_stack	*temp;

	temp = s;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	stack_len(t_stack *s)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = s;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	is_dup(char **arr, int flag)
{
	int	i;
	int	j;

	i = flag;
	while (arr[++i])
	{
		j = i;
		while (arr[++j])
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int		i;
	long	multiplier;
	long	num;

	i = 0;
	multiplier = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			multiplier = -1;
	num = 0;
	while (str[i] && ft_isdigit(str[i]))
		num = (num * 10) + (str[i++] - '0');
	return (num * multiplier);
}
