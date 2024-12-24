/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:21:00 by hkheired          #+#    #+#             */
/*   Updated: 2024/11/01 10:47:28 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	parse_string(t_list **list_tab, char *arg)
{
	char	**result;
	int		i;

	i = 0;
	result = ft_split(arg, ' ');
	if (!result)
		handle_error(list_tab);
	while (result[i])
	{
		val_add(list_tab, result[i]);
		i++;
	}
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	val_add(t_list **list_tab, char *arg)
{
	t_list	*node;
	long	result;

	check_num(arg, list_tab);
	if (ft_strchr(arg, ' '))
		parse_string(list_tab, arg);
	else
	{
		result = ft_atoi(arg);
		if ((result >= 2147483648) || check_dub(*list_tab, result))
			handle_error(list_tab);
		node = ft_lstnew((int)result);
		if (!node)
			handle_error(list_tab);
		ft_lstadd_back(list_tab, node);
	}
}

t_stack	*copy_list_tab(t_list **list_tab, t_stack *result)
{
	int		len_tab;
	t_list	*temp;

	len_tab = 0;
	temp = *list_tab;
	while (temp)
	{
		len_tab++;
		temp = temp->next;
	}
	result->index = malloc((len_tab) * sizeof(int));
	if (!result->index)
		handle_error(list_tab);
	len_tab = 0;
	temp = *list_tab;
	while (temp)
	{
		result->index[len_tab++] = temp->content;
		temp = temp->next;
	}
	ft_lstclear(list_tab, &delete_data);
	result->size = len_tab;
	return (result);
}

t_stack	*parse(int argc, char **argv)
{
	t_list	*list_tab;
	t_stack	*result;
	int		i;

	list_tab = NULL;
	i = 1;
	while (i < argc)
	{
		val_add(&list_tab, argv[i++]);
	}
	result = malloc(sizeof(t_stack));
	if (!result)
		handle_error(&list_tab);
	return (copy_list_tab(&list_tab, result));
}
/*
	fn: parse_string it split the string when it see whitespace when it
		check if number validate the criteria then add it t0 the list 
		after that free the temp list used to hold the string.
		
	fn: val_add it handle the case of string and case of args and 
		case of both string anad arg by function ft_strchr.
		
	fn: copy_list_tab it copy the list in array.

	fn: parse it make a val_add fn and return the array 
		copied in copy_list_tab fn.
*/
