/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:35:21 by hkheired          #+#    #+#             */
/*   Updated: 2024/08/28 12:21:01 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	check_sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size)
	{
		if (stack->index[i - 1] > stack->index[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_r_sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size)
	{
		if (stack->index[i - 1] < stack->index[i])
			return (0);
		i++;
	}
	return (1);
}

//
//	fn: check_sorted checked if the 
//	stack is sorted in ascending order.
//	fn: check_r_sorted is used to checks if the 
//	stack is sorted in descending order to handel 
//	the cases in sort 3 numbers.
