/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:21:51 by rgiraud           #+#    #+#             */
/*   Updated: 2024/08/29 11:46:14 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_a->size;
	if (stack_b->size == 0)
		return ;
	while (i > 0)
	{
		stack_a->index[i] = stack_a->index[i - 1];
		i--;
	}
	stack_a->index[0] = stack_b->index[0];
	stack_a->size++;
	stack_b->size--;
	while (i < stack_b->size)
	{
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->size;
	if (stack_a->size == 0)
		return ;
	while (i > 0)
	{
		stack_b->index[i] = stack_b->index[i - 1];
		i--;
	}
	stack_b->index[0] = stack_a->index[0];
	stack_b->size++;
	stack_a->size--;
	while (i < stack_a->size)
	{
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	ft_printf("pb\n");
}
