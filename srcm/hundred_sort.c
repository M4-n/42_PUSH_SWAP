/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:14:53 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 13:28:45 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	change_stack(t_stack **temp, t_stack **bottom)
{
	*temp = (*temp)->next;
	*bottom = (*bottom)->prev;
}

void	push_back(t_stack **a, t_stack **b)
{
	int	db;
	int	len_b;

	db = get_da(find_max(b));
	len_b = stack_len(*b);
	if (db <= len_b / 2)
		same_rotate(a, b, 0, db);
	else
		same_rrotate(a, b, 0, len_b - db);
	while (*b)
	{
		o_p(b, a);
		ft_printf("pa\n");
	}
}

void	sort_onehund(t_stack **a, int len_a, int chunknum)
{
	t_stack	*b;
	t_stack	*temp;
	t_stack	*bottom;

	b = NULL;
	while (++chunknum <= CHUNKONE && *a)
	{
		temp = *a;
		bottom = find_bottom(a);
		while (len_a > 0 && temp && bottom)
		{
			if (temp->chunk != chunknum && bottom->chunk != chunknum)
				change_stack(&temp, &bottom);
			else
			{
				if (temp->chunk == chunknum)
					place(a, &b, temp, len_a--);
				else if (bottom->chunk == chunknum)
					place(a, &b, bottom, len_a--);
				temp = *a;
				bottom = find_bottom(a);
			}
		}
	}
	push_back(a, &b);
}

void	sort_fivehund(t_stack **a, int len_a)
{
	t_stack	*b;
	t_stack	*temp;
	int		chunknum;

	b = NULL;
	chunknum = 0;
	while (++chunknum <= CHUNKFIVE && *a)
	{
		temp = *a;
		while (len_a > 0 && temp)
		{
			if (temp->chunk != chunknum)
				temp = temp->next;
			else
			{
				place(a, &b, temp, len_a);
				temp = *a;
				len_a--;
			}
		}
	}
	push_back(a, &b);
}
