/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:28:21 by rgiraud           #+#    #+#             */
/*   Updated: 2024/08/29 11:56:40 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ra(t_stack *stack_a)
{
	rotate_quiet(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate_quiet(stack_b);
	ft_printf("rb\n");
}

void	rotate_quiet(t_stack *stack_a)
{
	int	i;
	int	temp;

	if (stack_a->size < 2)
		return ;
	i = 0;
	temp = stack_a->index[0];
	while (i < stack_a->size - 1)
	{
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->index[i] = temp;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_quiet(stack_a);
	rotate_quiet(stack_b);
	ft_printf("rr\n");
}
