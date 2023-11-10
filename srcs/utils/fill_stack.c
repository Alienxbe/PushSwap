/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:38:43 by marykman          #+#    #+#             */
/*   Updated: 2023/11/11 00:39:49 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_memory.h"
#include "ft_ctype.h"
#include "ft_string.h"
#include "ft_dlist.h"
#include "ft_printf.h"

static int	in_list(int *list, int index, int n)
{
	int i;

	i = -1;
	while (++i < --index)
		if (list[i] == n)
			return (1);
	return (0);
}

static size_t	array_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

t_dlist	*fill_stack(int argc, char **argv, int **content)
{
	t_dlist	*stack;
	t_dlist	*new;
	int		i;

	stack = NULL;
	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = array_len(argv);
		i = -1;
	}
	*content = (int *)ft_calloc(argc - 1, sizeof(int));
	if (!*content)
		return (NULL);
	while (++i < argc)
	{
		(*content)[i - 1] = ft_atoi(argv[i]);
		if (!(ft_isnumber(argv[i]) || *argv[i] == '-' || *argv[i] == '+')
			|| in_list(*content, i - 1, (*content)[i - 1]))
		{
			ft_printf("Error!\n");
			return (NULL);
		}
		new = ft_dlstnew((*content) + i - 1);
		if (!new)
			return (NULL);
		ft_dlstadd_back(&stack, new);
	}
	return (stack);
}
