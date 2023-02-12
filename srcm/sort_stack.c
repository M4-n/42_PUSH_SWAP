/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:24:09 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 13:28:58 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	while (!is_sorted(*a))
	{
		top = (*a)->num;
		mid = (*a)->next->num;
		bot = (*a)->next->next->num;
		if (top > mid && top < bot)
		{
			o_s(*a);
			ft_printf("sa\n");
		}
		else if (top > mid && top > bot)
		{
			o_r(a);
			ft_printf("ra\n");
		}
		else if (top < mid && mid > bot)
		{
			o_rr(a);
			ft_printf("rra\n");
		}
	}
}

void	push_back_five(t_stack **a, t_stack **b, int len)
{
	t_stack	*temp;
	t_stack	*top;
	int		i;

	temp = *a;
	top = *a;
	i = 0;
	while (++i && temp->next && (*b)->num < find_max(a)->num)
	{
		if (temp->num < (*b)->num && (*b)->num < temp->next->num)
			break ;
		temp = temp->next;
	}
	while (temp->next)
		temp = temp->next;
	if ((temp->num < (*b)->num) && ((*b)->num < top->num))
		i = 0;
	else if (((*b)->num < find_min(a)->num) || (find_max(a)->num < (*b)->num))
		i = get_da(find_min(a));
	if (i <= len / 2)
		same_rotate(a, b, i, 0);
	else if (i > len / 2)
		same_rrotate(a, b, len - i, 0);
	o_p(b, a);
	ft_printf("pa\n");
}

void	sort_five(t_stack **a, int len)
{
	t_stack	*b;
	int		da;

	b = NULL;
	da = len;
	while (da-- > 3)
	{
		o_p(a, &b);
		ft_printf("pb\n");
	}
	sort_three(a);
	while (b)
		push_back_five(a, &b, stack_len(*a));
	da = get_da(find_min(a));
	if (da <= len / 2)
		same_rotate(a, &b, da, 0);
	else if (da > len / 2)
		same_rrotate(a, &b, len - da, 0);
}

void	sort_stack(t_stack **a, int len)
{
	if (is_sorted(*a))
		return ;
	else if (len == 2)
	{
		o_s(*a);
		ft_printf("sa\n");
	}
	else if (len == 3)
		sort_three(a);
	else if (len <= 5)
		sort_five(a, len);
	else
		hundred_sort(a, len);
}
