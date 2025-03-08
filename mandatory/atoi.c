/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:21:29 by taya              #+#    #+#             */
/*   Updated: 2025/03/08 16:33:30 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi(const char *str)
{
	int			i;
	long long	res;
	int			sign;
    int flag;

	i = 0;
	res = 0;
	sign = 1;
    flag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && (-res < INT_MIN)))
			print_error();
		i++;
	}
    if (flag && !is_digit(str[i]))
        print_error();
	return ((int)(res * sign));
}
