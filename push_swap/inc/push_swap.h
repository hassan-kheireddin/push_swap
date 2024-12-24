/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:20:08 by hkheired          #+#    #+#             */
/*   Updated: 2024/08/29 09:14:32 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../all_libft/includes/libft.h"
# include "../all_libft/includes/ft_printf.h"

typedef struct s_stack
{
	int					*index;
	int					size;
}						t_stack;

typedef struct s_best_moves
{
	int					nrb;
	int					nrrb;
	int					nra;
	int					nrra;
	int					nrr;
	int					nrrr;
	int					tm;
}						t_best_moves;

typedef struct s_max_value
{
	int					min;
	int					max_first;
	int					max_second;
	int					max_third;
	int					max_fourth;
	int					max_fifth;
	int					median;
	int					*copy_tab;
	int					size;
}						t_max_value;

// =================Operations====================
void	swap_quiet(t_stack *stack_a);
void	rotate_quiet(t_stack *stack_a);
void	reverse_r_quiet(t_stack *stack_a);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
// ===============================================

// ===============Checking========================
int		check_sorted(t_stack *stack);
int		check_r_sorted(t_stack *stack);
int		check_dub(t_list *list_tab, int n);
void	check_num(char *arg, t_list **list_tab);
// ===============================================

// =================Sorting=============================
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
int		partition(int *tab, int start, int end);
void	quick_sort(int *tab, int start, int end);
void	push_median(t_stack *stack_a, t_stack *stack_b, int median);
void	ft_back_to_back(t_stack *stack_a, t_stack *stack_b,
			t_max_value *mv, int shortest);
void	push_pre_sort(t_stack *stack_a, t_stack *stack_b, t_max_value *mv);
void	opti_sort(t_stack *a, t_stack *b);
// =====================================================

// ================Utils============================================
void	free_stack(t_stack *stack_a, t_stack *stack_b);
void	handle_error_stack(t_stack *stack_a, t_stack *stack_b);
int		find_min(t_stack *stack);
void	delete_data(int content);
void	handle_error(t_list **list_tab);
void	swap(int *x, int *y);
void	init_stack_b(t_stack *stack_a, t_stack **stack_b);
void	handle_big_error(t_stack *stack_a, t_stack *stack_b,
			t_max_value *mv, t_best_moves *bm);
// =================================================================

//====================Parser========================================
void	parse_string(t_list **list_tab, char *arg);
void	val_add(t_list **list_tab, char *arg);
t_stack	*copy_list_tab(t_list **list_tab, t_stack *result);
t_stack	*parse(int argc, char **argv);
//==================================================================

//==================Moves===========================================
int		next_number(int number, t_stack *stack_a);
void	count_a(t_stack *a, int next_number, t_best_moves *bm);
int		total_moves(t_best_moves *bm);
void	calculate_doubles(t_best_moves *bm);
void	calculate_best_moves(t_stack *stack_a, t_stack *stack_b,
			t_best_moves *bm, t_max_value *mv);
void	do_moves(t_stack *a, t_stack *b, t_best_moves *bm);
void	init_moves(t_best_moves *bm);
void	copy_moves(t_best_moves *bm, t_best_moves *bm_temp);
int		is_max_value(int x, t_max_value *mv);
//==========================================================================

#endif
