/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:28:21 by rgiraud           #+#    #+#             */
/*   Updated: 2024/08/29 11:56:40 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rra(t_stack *stack_a)
{
	reverse_r_quiet(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	reverse_r_quiet(stack_b);
	ft_printf("rrb\n");
}

void	reverse_r_quiet(t_stack *stack_a)
{
	int	i;
	int	temp;

	if (stack_a->size < 2)
		return ;
	i = stack_a->size - 1;
	temp = stack_a->index[stack_a->size - 1];
	while (i > 0)
	{
		stack_a->index[i] = stack_a->index[i - 1];
		i--;
	}
	stack_a->index[0] = temp;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_r_quiet(stack_a);
	reverse_r_quiet(stack_b);
	ft_printf("rrr\n");
}
