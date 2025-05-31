/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:22:45 by hkheired          #+#    #+#             */
/*   Updated: 2024/08/28 13:23:41 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_max_value	*init_mv(t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	t_max_value	*mv;

	mv = malloc(sizeof(t_max_value));
	if (!mv)
		handle_error_stack(stack_a, stack_b);
	mv->copy_tab = malloc(stack_a->size * sizeof(int));
	if (!mv->copy_tab)
		handle_error_stack(stack_a, stack_b);
	mv->size = stack_a->size;
	i = -1;
	while (++i < stack_a->size)
		mv->copy_tab[i] = stack_a->index[i];
	quick_sort(mv->copy_tab, 0, stack_a->size - 1);
	if (stack_a->size % 2 == 0)
		mv->median = mv->copy_tab[(stack_a->size - 2) / 2];
	else
		mv->median = mv->copy_tab[(stack_a->size - 1) / 2];
	mv->min = mv->copy_tab[0];
	mv->max_first = mv->copy_tab[stack_a->size - 1];
	mv->max_second = mv->copy_tab[stack_a->size - 2];
	mv->max_third = mv->copy_tab[stack_a->size - 3];
	mv->max_fourth = mv->copy_tab[stack_a->size - 4];
	mv->max_fifth = mv->copy_tab[stack_a->size - 5];
	return (mv);
}

void	push_median(t_stack *stack_a, t_stack *stack_b, int median)
{
	int	shortest;

	shortest = 0;
	while (stack_a->index[shortest] != median)
		shortest++;
	if (shortest <= stack_a->size - shortest)
	{
		while (shortest--)
			ra(stack_a);
	}
	else
	{
		shortest = stack_a->size - shortest;
		while (shortest--)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	ft_back_to_back(t_stack *stack_a, t_stack *stack_b,
	t_max_value *mv, int shortest)
{
	t_best_moves	*bm;

	bm = malloc(sizeof(t_best_moves));
	if (!bm)
		handle_big_error(stack_a, stack_b, mv, bm);
	init_moves(bm);
	while (stack_b->size)
	{
		calculate_best_moves(stack_a, stack_b, bm, mv);
		do_moves(stack_a, stack_b, bm);
		bm->tm = INT_MAX;
	}
	while (stack_a->index[shortest] != mv->min)
		shortest++;
	if (shortest <= stack_a->size - shortest)
		while (shortest--)
			ra(stack_a);
	else
	{
		shortest = stack_a->size - shortest;
		while (shortest--)
			rra(stack_a);
	}
	free(bm);
}

void	push_pre_sort(t_stack *stack_a, t_stack *stack_b, t_max_value *mv)
{
	int	i;
	int	size_a;

	size_a = stack_a->size;
	i = 0;
	if (stack_a->size == 5)
		return ;
	while (i < size_a)
	{
		if (!is_max_value(stack_a->index[0], mv))
		{
			pb(stack_a, stack_b);
			if (stack_b->index[0] > mv->median)
				rb(stack_b);
		}
		else
			ra(stack_a);
		i++;
	}
}

void	opti_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_max_value	*mv;

	if (check_sorted(stack_a))
		return ;
	mv = init_mv(stack_a, stack_b);
	push_median(stack_a, stack_b, mv->median);
	push_pre_sort(stack_a, stack_b, mv);
	if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else
		sort_five(stack_a, stack_b);
	ft_back_to_back(stack_a, stack_b, mv, 0);
	free(mv->copy_tab);
	free(mv);
}
