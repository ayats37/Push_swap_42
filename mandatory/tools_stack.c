/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:00:57 by taya              #+#    #+#             */
/*   Updated: 2025/03/09 16:20:40 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *ft_strcat(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	
	while(s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
char **parse_args(int argc, char **argv, int *count, int *free_flag)
{
    char **args;
    char *ar;
    int i;
	char *tmp;

    if (argc < 2)
        return NULL;
	ar = NULL;
    ar = ft_strdup("");
    if (!ar)
        return NULL;		
	tmp = ar;
	i = 1;
    while (i < argc)
    {
        tmp = ft_strjoin(ar, argv[i]);
        if (!tmp)
            return (free(ar), NULL);
		ar = tmp;
		ft_strcat(ar, " ");
        i++;
    }
    args = ft_split(ar, ' ');
	int j = 0;
	while (args[j])
	{
		printf("%s\n", args[j]);
		j++;
	}
    free(ar);
    *count = 0;
    while (args && args[*count])
        (*count)++;
    return (*free_flag = 1, args);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->size <= 1)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
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

int	duplicate(char **args, int count)
{
	int	i;
	int	j;

	i = 1;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (atoi(args[i]) == atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

