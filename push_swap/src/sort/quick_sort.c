/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:31:10 by hkheired          #+#    #+#             */
/*   Updated: 2024/08/28 09:33:34 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap_quick(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	partition(int *tab, int start, int end)
{
	int	pivot;
	int	start_tab;

	start_tab = start;
	pivot = tab[start];
	start++;
	while (start <= end)
	{
		while (start <= end && tab[start] < pivot)
			start++;
		while (start <= end && tab[end] > pivot)
			end--;
		if (start < end)
			swap_quick(tab + start, tab + end);
	}
	swap_quick(tab + start_tab, tab + end);
	return (end);
}

void	quick_sort(int *tab, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(tab, start, end);
		quick_sort(tab, start, pivot_index - 1);
		quick_sort(tab, pivot_index + 1, end);
	}
}
