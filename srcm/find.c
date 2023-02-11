/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:59:03 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 12:51:27 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_max(t_stack **s)
{
	t_stack	*temp;
	t_stack	*max;

	if (!(*s))
		return (NULL);
	max = *s;
	if (!max->next)
		return (max);
	temp = (*s)->next;
	while (temp)
	{
		if (max->num < temp->num)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_stack	*find_min(t_stack **s)
{
	t_stack	*temp;
	t_stack	*min;

	if (!(*s))
		return (NULL);
	min = *s;
	if (!min->next)
		return (min);
	temp = (*s)->next;
	while (temp)
	{
		if (min->num > temp->num)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_stack	*find_bottom(t_stack **s)
{
	t_stack	*bottom;

	if (!(*s))
		return (NULL);
	bottom = *s;
	if (!bottom->next)
		return (bottom);
	while (bottom->next)
		bottom = bottom->next;
	return (bottom);
}
