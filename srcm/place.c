/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:46:40 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 13:19:43 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//da = distance from an element to top
int	get_da(t_stack *a)
{
	t_stack	*temp;
	int		i;

	i = -1;
	temp = a;
	while (temp)
	{
		temp = temp->prev;
		i++;
	}
	return (i);
}

//db = distance from where to put an element to top
int	get_db(t_stack *b, int a_num, int len_b)
{
	t_stack	*temp;
	t_stack	*top;
	int		i;

	if (!b)
		return (0);
	temp = b;
	top = b;
	i = 0;
	while (++i && temp->next)
	{
		if (temp->num > a_num && a_num > temp->next->num)
			return (i);
		temp = temp->next;
	}
	if (len_b > 2 && temp->num > a_num && a_num > top->num)
		return (0);
	if (len_b > 2 && (a_num < find_min(&b)->num
			|| find_max(&b)->num < a_num))
		return (get_da(find_max(&b)));
	return (0);
}

void	place(t_stack **a, t_stack **b, t_stack *marker, int len_a)
{
	int	da;
	int	db;
	int	len_b;

	len_b = stack_len(*b);
	if ((len_b == 2) && ((*b)->num < (*b)->next->num))
	{
		o_s(*b);
		ft_printf("sb\n");
	}
	da = get_da(marker);
	db = get_db(*b, marker->num, len_b);
	if (da <= len_a / 2 && db <= len_b / 2)
		same_rotate(a, b, da, db);
	else if (da > len_a / 2 && db > len_b / 2)
		same_rrotate(a, b, len_a - da, len_b - db);
	else if (da <= len_a / 2 && db > len_b / 2)
		aubl_rotate(a, b, da, db);
	else if (da > len_a / 2 && db <= len_b / 2)
		albu_rotate(a, b, da, db);
	o_p(a, b);
	ft_printf("pb\n");
}
