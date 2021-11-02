/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:48:24 by mykman            #+#    #+#             */
/*   Updated: 2021/11/02 11:03:50 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_return(t_list *stack, int *content_list, int return_val)
{
	free(content_list);
	ft_lstclear(&stack, NULL);
	return (return_val);
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*new;
	int		*content_list;
	int		i;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	content_list = (int *)ft_calloc(argc - 1, sizeof(int));
	if (!content_list)
		return (1);
	i = 0;
	while (++i < argc)
	{
		content_list[i - 1] = ft_atoi(argv[i]);
		new = ft_lstnew(content_list + i - 1);
		if (!ft_isnumber(argv[i])
			|| in_list(content_list, i - 1, content_list[i - 1])
			|| !new)
			return (free_return(stack_a, content_list, 1));
		ft_lstadd_back(&stack_a, new);
	}
	return (free_return(stack_a, content_list, 0));
}
