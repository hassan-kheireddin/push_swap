/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_m.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:02:12 by hkheired          #+#    #+#             */
/*   Updated: 2024/08/28 13:18:26 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	do_moves(t_stack *stack_a, t_stack *stack_b, t_best_moves *bm)
{
	while (bm->nrr--)
		rr(stack_a, stack_b);
	while (bm->nrrr--)
		rrr(stack_a, stack_b);
	while (bm->nrrb--)
		rrb(stack_b);
	while (bm->nrb--)
		rb(stack_b);
	while (bm->nra--)
		ra(stack_a);
	while (bm->nrra--)
		rra(stack_a);
	pa(stack_a, stack_b);
}

void	init_moves(t_best_moves *bm)
{
	bm->nra = 0;
	bm->nrb = 0;
	bm->nrr = 0;
	bm->nrrr = 0;
	bm->tm = INT_MAX;
	bm->nrra = 0;
	bm->nrrb = 0;
}

void	copy_moves(t_best_moves *bm, t_best_moves *bm_temp)
{
	bm->nra = bm_temp->nra;
	bm->nrb = bm_temp->nrb;
	bm->nrra = bm_temp->nrra;
	bm->nrrb = bm_temp->nrrb;
	bm->nrrr = bm_temp->nrrr;
	bm->nrr = bm_temp->nrr;
	bm->tm = bm_temp->tm;
}

int	is_max_value(int x, t_max_value *mv)
{
	return (x == mv->max_first || x == mv->max_second || x == mv->max_third
		|| x == mv->max_fifth || x == mv->max_fourth);
}
