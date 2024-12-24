/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimumum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:04:34 by hkheired          #+#    #+#             */
/*   Updated: 2024/08/28 12:09:36 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;
	int	i;

	i = 1;
	min = stack->index[0];
	while (i < stack->size)
	{
		if (min > stack->index[i])
			min = stack->index[i];
		i++;
	}
	return (min);
}
// fn: find_min is used to find the minimum value in the stack.
