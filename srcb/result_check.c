/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:44:00 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 12:46:08 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	check_swap(t_stack **a, t_stack **b, char *line)
{
	if (line[1] == 'a')
		o_s(*a);
	else if (line[1] == 'b')
		o_s(*b);
	else
	{
		o_s(*a);
		o_s(*b);
	}
}

void	check_rotate(t_stack **a, t_stack **b, char *line)
{
	if (line[1] == 'a')
		o_r(a);
	else if (line[1] == 'b')
		o_r(b);
	else
	{
		o_r(a);
		o_r(b);
	}
}

void	check_rrotate(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		o_rr(a);
	else if (line[2] == 'b')
		o_rr(b);
	else
	{
		o_rr(a);
		o_rr(b);
	}
}

void	check_push(t_stack **a, t_stack **b, char *line)
{
	if (line[1] == 'a')
		o_p(b, a);
	else
		o_p(a, b);
}

void	check_result(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'p')
		check_push(a, b, line);
	else if (line[0] == 's')
		check_swap(a, b, line);
	else if (line[0] == 'r' && ft_strlen(line) < 4)
		check_rotate(a, b, line);
	else if (line[0] == 'r' && ft_strlen(line) == 4)
		check_rrotate(a, b, line);
}
