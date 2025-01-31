/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:41:08 by hkheired          #+#    #+#             */
/*   Updated: 2025/01/31 19:36:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->index);
	free(stack_b->index);
	free(stack_a);
	free(stack_b);
}

void	handle_error_stack(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a, stack_b);
	exit(EXIT_FAILURE);
}

void	delete_data(int content)
{
	(void)content;
}

void	handle_error(t_list **list_tab)
{
	ft_lstclear(list_tab, &delete_data);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	handle_big_error(t_stack *stack_a, t_stack *stack_b, t_max_value *mv,
		t_best_moves *bm)
{
	free(stack_a->index);
	free(stack_b->index);
	free(stack_a);
	free(stack_b);
	free(mv);
	free(bm);
	exit(EXIT_FAILURE);
}

//	fn: free_stack is used to free 
//	the stacks if error happen and in main function after finish sorting.
//	fn: handel_error_stack is used to 
//	free stacks and exit the program when error occured
//	fn: delete_data is used to free nodes of the list in order to free the list.
//	fn: handel_error is used to free list and exit when error happen.
//	fn: handel_big error is used to free all Data Sturctures and exit.
