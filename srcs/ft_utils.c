/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:05:01 by mykman            #+#    #+#             */
/*   Updated: 2021/11/03 23:16:34 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*fill_stack(int argc, char **argv, int **content)
{
	t_dlist	*stack;
	t_dlist	*new;
	int		i;

	stack = NULL;
	*content = (int *)ft_calloc(argc - 1, sizeof(int));
	if (!*content)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		(*content)[i - 1] = ft_atoi(argv[i]);
		if (!ft_isnumber(argv[i])
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

int	in_list(int *list, int index, int n)
{
	int i;

	i = -1;
	while (++i < --index)
		if (list[i] == n)
			return (1);
	return (0);
}

void	print_stack(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_printf("--------------------------------\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%5d\t|", *(int *)stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf("     \t|");
		if (stack_b)
		{
			ft_printf("\t%d\n", *(int *)stack_b->content);
			stack_b = stack_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("%5s\t|\t%s\n", "-", "-");
	ft_printf("%5s\t|\t%s\n", "A", "B");
}