/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:12:22 by hkheired          #+#    #+#             */
/*   Updated: 2024/08/28 12:02:54 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	init_stack_b(t_stack *stack_a, t_stack **stack_b)
{
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_b)
		handle_error_stack(stack_a, *stack_b);
	(*stack_b)->index = malloc(stack_a->size * sizeof(int));
	if (!(*stack_b)->index)
		handle_error_stack(stack_a, (*stack_b));
	(*stack_b)->size = 0;
}
// fn: init_stack_b is used to create an empty stack b.
