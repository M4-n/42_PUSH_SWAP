/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:14:32 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 12:53:26 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	format_error(char **arr, int flag)
{
	if (flag == -1)
		free_arr(arr);
	write(2, "Error\n", 6);
	exit(0);
}

void	stack_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	free_stack(t_stack **s)
{
	t_stack	*temp;

	while (*s)
	{
		temp = *s;
		*s = (*s)->next;
		free(temp);
	}
	free(s);
}

t_stack	**stack_init(int len)
{
	t_stack	**s;
	t_stack	*temp;

	s = (t_stack **)malloc(sizeof(t_stack *));
	*s = (t_stack *)malloc(sizeof(t_stack));
	(*s)->next = NULL;
	len--;
	while (len--)
	{
		temp = *s;
		(*s)->prev = (t_stack *)malloc(sizeof(t_stack));
		*s = (*s)->prev;
		(*s)->next = temp;
		temp->prev = *s;
	}
	(*s)->prev = NULL;
	return (s);
}
