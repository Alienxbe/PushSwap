/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:38:43 by marykman          #+#    #+#             */
/*   Updated: 2024/08/30 23:43:25 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_memory.h"
#include "ft_ctype.h"
#include "ft_string.h"
#include "ft_dlist.h"
#include "ft_printf.h"
#include "ft_math.h"

static int	in_list(int *list, int index, int n)
{
	int	i;

	i = -1;
	while (++i < index)
		if (list[i] == n)
			return (1);
	return (0);
}

static void	free_tab(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static size_t	array_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static int	add_new_element(char *str, int *content, int i, t_dlist	**stack)
{
	t_dlist	*new;
	char	*endptr;

	content[i] = (int)ft_strtol(str, &endptr, BASE_DECI);
	if (!*str
		|| ((*str == '-' || *str == '+') && !ft_isnumber(str + 1))
		|| ft_cmp_bn(str, "2147483647") > 0
		|| ft_cmp_bn(str, "-2147483648") > 0
		|| ft_strlen(str) != (size_t)(endptr - str)
		|| in_list(content, i, content[i]))
	{
		ft_fprintf(STDERR_FILENO, "Error\n");
		ft_dlstclear(stack, NULL);
		return (0);
	}
	new = ft_dlstnew(content + i);
	if (!new)
	{
		ft_dlstclear(stack, NULL);
		return (0);
	}
	ft_dlstadd_back(stack, new);
	return (1);
}

t_dlist	*fill_stack(int argc, char **argv, int **content)
{
	t_dlist	*stack;
	int		i;
	int		offset;

	stack = NULL;
	i = -1;
	offset = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (NULL);
		argc = array_len(argv);
		offset = 0;
	}
	*content = (int *)ft_calloc(argc - offset, sizeof(int));
	if (!*content)
		return (NULL);
	while (++i < argc - offset)
		if (!add_new_element(argv[i + offset], *content, i, &stack))
			break ;
	if (offset == 0)
		free_tab(argv);
	return (stack);
}
