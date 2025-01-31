/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:07:24 by hkheired          #+#    #+#             */
/*   Updated: 2025/01/31 19:31:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long	ft_atoi(const char *nptr)
{
	long	result;
	int	sign;
	size_t	i;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == '\v' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
