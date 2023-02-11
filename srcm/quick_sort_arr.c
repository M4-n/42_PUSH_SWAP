/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:46:46 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 13:30:53 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(char **arr, int start, int end)
{
	int	i;
	int	j;

	i = start - 1;
	j = i;
	while (++j < end)
		if (ft_atoi(arr[j]) <= ft_atoi(arr[end]))
			ft_swap(&arr[++i], &arr[j]);
	ft_swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

void	quick_sort_arr(char **arr, int start, int end, int i)
{
	int	*temp;
	int	pivot;

	if (start == 0)
		end -= 1;
	temp = malloc(sizeof(int) * end);
	temp[++i] = start;
	temp[++i] = end;
	while (i > -1)
	{
		end = temp[i--];
		start = temp[i--];
		pivot = partition(arr, start, end);
		if (pivot - 1 > start)
		{
			temp[++i] = start;
			temp[++i] = pivot - 1;
		}
		if (pivot + 1 < end)
		{
			temp[++i] = pivot + 1;
			temp[++i] = end;
		}
	}
	free(temp);
}
