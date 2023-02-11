/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:56:48 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 15:28:32 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_cnum(t_stack **a, int min, int max, int chunknum)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (min <= temp->num && temp->num <= max)
			temp->chunk = chunknum;
		temp = temp->next;
	}
}

void	parse_chunk(t_stack **a, char **arr, int len, int start)
{
	int	range;
	int	chunknum;
	int	chunk;
	int	end;

	chunk = CHUNKONE;
	if (len > 100)
		chunk = CHUNKFIVE;
	range = len / chunk;
	end = 1;
	chunknum = 1;
	while (chunknum <= chunk && range > 0)
	{
		while (end > len - 1)
			end--;
		if (chunknum == chunk && end < len - 1)
			while (arr[end + 1])
				end++;
		assign_cnum(a, ft_atoi(arr[start]), ft_atoi(arr[end]), chunknum);
		start += range;
		end += range;
		chunknum++;
	}
	if (range <= 0)
		assign_cnum(a, INT_MIN, INT_MAX, 1);
}
