/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:34:28 by hkheired          #+#    #+#             */
/*   Updated: 2024/08/28 13:06:12 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	next_number(int number, t_stack *stack_a)
{
	int	i;
	int	next_n;
	int	found;

	found = 0;
	i = 0;
	next_n = INT_MAX;
	while (i < stack_a->size)
	{
		if (stack_a->index[i] > number && stack_a->index[i] < next_n)
		{
			next_n = stack_a->index[i];
			found = 1;
		}
		i++;
	}
	if (!found)
	{
		next_n = stack_a->index[0];
		i = 0;
		while (++i < stack_a->size)
			if (stack_a->index[i] < next_n)
				next_n = stack_a->index[i];
	}
	return (next_n);
}

void	count_a(t_stack *a, int next_number, t_best_moves *bm)
{
	int	shortest;

	shortest = 0;
	while (shortest < a->size && a->index[shortest] != next_number)
		shortest++;
	if (shortest <= a->size - shortest)
		bm->nra = shortest;
	else
		bm->nrra = a->size - shortest;
}

int	total_moves(t_best_moves *bm)
{
	int	total_mov;

	total_mov = bm->nra + bm->nrb + bm->nrrb + bm->nrra + bm->nrr + bm->nrrr;
	bm->tm = total_mov;
	return (total_mov);
}

void	calculate_doubles(t_best_moves *bm)
{
	while (bm->nra && bm->nrb)
	{
		bm->nra--;
		bm->nrb--;
		bm->nrr++;
	}
	while (bm->nrra && bm->nrrb)
	{
		bm->nrra--;
		bm->nrrb--;
		bm->nrrr++;
	}
}

void	calculate_best_moves(t_stack *stack_a, t_stack *stack_b,
	t_best_moves *bm, t_max_value *mv)
{
	int				i;
	int				next_n;
	t_best_moves	*bm_temp;

	bm_temp = malloc(sizeof(t_best_moves));
	if (!bm_temp)
		handle_big_error(stack_a, stack_b, mv, bm);
	i = 0;
	while (i < stack_b->size)
	{
		init_moves(bm_temp);
		if (i <= stack_b->size - i)
			bm_temp->nrb = i;
		else
			bm_temp->nrrb = stack_b->size - i;
		next_n = next_number(stack_b->index[i], stack_a);
		count_a(stack_a, next_n, bm_temp);
		calculate_doubles(bm_temp);
		if (total_moves(bm_temp) < bm->tm)
			copy_moves(bm, bm_temp);
		if (bm->tm == 0 || bm->tm == 1)
			break ;
		i++;
	}
	free(bm_temp);
}
//fn: next_number is used to get the smallest number 
//that is greater than the target number.
//fn: count_a it counts the number of rotation 
//or rev-rotation in stack a and return them byh small equation.
//fn: total_moves it add all operation to calculate 
//the total move to get the number in the right place.
//fn: calculate doubles is used to make rrr and rr 
//instead of ra rb and rra and rrb at the same time.
//fn: calculate_best_move is the most important 
//fuction which calculate the moves needed for each 
//number to come in right place by using some functions.
