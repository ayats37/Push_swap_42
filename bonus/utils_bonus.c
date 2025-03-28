/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 02:08:26 by taya              #+#    #+#             */
/*   Updated: 2025/03/15 00:56:49 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_duplicate(char **args, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (f_atoi(args[i]) == f_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_nbr(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	validate_numbers(char **args, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!valid_nbr(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_only_whitespace(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

char	*join_args(int argc, char **argv)
{
	char	*ar;
	char	*tmp;
	int		i;

	ar = ft_strdup(argv[1]);
	if (!ar)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		if (argv[i][0] == '\0' || is_only_whitespace(argv[i]))
			return (free(ar), NULL);
		tmp = ft_strjoin(ar, " ");
		if (!tmp)
			return (free(ar), NULL);
		free(ar);
		ar = tmp;
		tmp = ft_strjoin(ar, argv[i++]);
		if (!tmp)
			return (free(ar), NULL);
		free(ar);
		ar = tmp;
	}
	return (ar);
}
