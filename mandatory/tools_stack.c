/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:00:57 by taya              #+#    #+#             */
/*   Updated: 2025/03/13 19:33:51 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ar = tmp;
		tmp = ft_strjoin(ar, argv[i++]);
		if (!tmp)
			return (free(ar), NULL);
		free(ar);
		ar = tmp;
	}
	return (ar);
}

char	**parse_args(int argc, char **argv, int *count)
{
	char	**args;
	char	*ar;

	ar = join_args(argc, argv);
	args = ft_split(ar, ' ');
	free(ar);
	*count = 0;
	while (args && args[*count])
		(*count)++;
	return (args);
}
