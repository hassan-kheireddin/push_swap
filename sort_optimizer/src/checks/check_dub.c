/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:20:47 by hkheired          #+#    #+#             */
/*   Updated: 2024/08/28 12:17:25 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	check_dub(t_list *list_tab, int n)
{
	while (list_tab)
	{
		if (list_tab->content == n)
			return (1);
		list_tab = list_tab->next;
	}
	return (0);
}
// fn: check_dub is used to check if there exit any repeated number in the list.
