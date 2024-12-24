/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:21:51 by rgiraud           #+#    #+#             */
/*   Updated: 2024/08/29 11:56:40 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sa(t_stack *stack_a)
{
	swap_quiet(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap_quiet(stack_b);
	ft_printf("sb\n");
}

void	swap_quiet(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->index[0];
	stack_a->index[0] = stack_a->index[1];
	stack_a->index[1] = temp;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_quiet(stack_a);
	swap_quiet(stack_b);
	ft_printf("ss\n");
}
