/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:32:27 by hkheired          #+#    #+#             */
/*   Updated: 2024/08/27 12:31:17 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_two(t_stack *stack)
{
	if (!check_sorted(stack))
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	if (check_sorted(stack))
		return ;
	if (check_r_sorted(stack))
	{
		ra(stack);
		sa(stack);
	}
	else if (stack->index[0] > stack->index[1]
		&& stack->index[0] > stack->index[2])
		ra(stack);
	else if (stack->index[0] < stack->index[1]
		&& stack->index[0] > stack->index[2])
		rra(stack);
	else if (stack->index[1] > stack->index[2]
		&& stack->index[1] > stack->index[0])
	{
		rra(stack);
		sa(stack);
	}
	else
		sa(stack);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	if (check_sorted(stack_a))
		return ;
	min = find_min(stack_a);
	while (stack_a->index[0] != min && stack_a->index[stack_a->size - 1] != min)
		ra(stack_a);
	if (stack_a->index[stack_a->size -1] == min)
		rra(stack_a);
	if (check_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = find_min(stack_a);
	if (check_sorted(stack_a))
		return ;
	while (stack_a->index[0] != min && stack_a->index[stack_a->size - 1] != min
		&& stack_a->index[stack_a->size - 2] != min)
		ra(stack_a);
	if (stack_a->index[stack_a->size - 2] == min)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (stack_a->index[stack_a->size - 1] == min)
		rra(stack_a);
	if (check_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
