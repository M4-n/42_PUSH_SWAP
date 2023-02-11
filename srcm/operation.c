/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:04:30 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 12:52:51 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//push top of src to top of dst
void	o_p(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	temp = *src;
	if (!temp)
		return ;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->next = *dst;
	if (*dst)
		(*dst)->prev = temp;
	*dst = temp;
}

//swap 2 top elements' position
void	o_s(t_stack *top)
{
	int	temp;

	if (!top || !top->next)
		return ;
	temp = top->num;
	top->num = top->next->num;
	top->next->num = temp;
}

//rotate up
void	o_r(t_stack **top)
{
	t_stack	*old_last;
	t_stack	*new_last;

	if (!top || !(*top) || (stack_len(*top) == 1))
		return ;
	old_last = *top;
	new_last = *top;
	while (old_last->next)
		old_last = old_last->next;
	*top = (*top)->next;
	(*top)->prev = NULL;
	new_last->prev = old_last;
	new_last->next = NULL;
	old_last->next = new_last;
}

//rotate down
void	o_rr(t_stack **new_top)
{
	t_stack	*last;
	t_stack	*old_top;

	if (!new_top || !(*new_top) || (stack_len(*new_top) == 1))
		return ;
	old_top = *new_top;
	while ((*new_top)->next)
		*new_top = (*new_top)->next;
	last = (*new_top)->prev;
	(*new_top)->prev = NULL;
	old_top->prev = *new_top;
	last->next = NULL;
	(*new_top)->next = old_top;
}
