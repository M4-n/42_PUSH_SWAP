/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:34:52 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 12:54:23 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	same_rotate(t_stack **a, t_stack **b, int da, int db)
{
	while (da && db)
	{
		o_r(a);
		o_r(b);
		da--;
		db--;
		ft_printf("rr\n");
	}
	while (da-- > 0)
	{
		o_r(a);
		ft_printf("ra\n");
	}
	while (db-- > 0)
	{
		o_r(b);
		ft_printf("rb\n");
	}
}

void	same_rrotate(t_stack **a, t_stack **b, int da, int db)
{
	while (da && db)
	{
		o_rr(a);
		o_rr(b);
		da--;
		db--;
		ft_printf("rrr\n");
	}
	while (da-- > 0)
	{
		o_rr(a);
		ft_printf("rra\n");
	}
	while (db-- > 0)
	{
		o_rr(b);
		ft_printf("rrb\n");
	}
}

void	aubl_rotate(t_stack **a, t_stack **b, int da, int db)
{
	int	d_diff;
	int	len_b;

	len_b = stack_len(*b);
	d_diff = da - db;
	if (d_diff < 0)
		d_diff *= -1;
	if (d_diff <= len_b - db)
	{
		same_rotate(a, b, da, db);
		return ;
	}
	db = len_b - db;
	while (da--)
	{
		o_r(a);
		ft_printf("ra\n");
	}
	while (db--)
	{
		o_rr(b);
		ft_printf("rrb\n");
	}
}

void	albu_rotate(t_stack **a, t_stack **b, int da, int db)
{
	int	d_diff;
	int	len_a;

	len_a = stack_len(*a);
	d_diff = da - db;
	if (d_diff < 0)
		d_diff *= -1;
	if (d_diff <= len_a - da)
	{
		same_rotate(a, b, da, db);
		return ;
	}
	da = len_a - da;
	while (db--)
	{
		o_r(b);
		ft_printf("rb\n");
	}
	while (da--)
	{
		o_rr(a);
		ft_printf("rra\n");
	}
}
