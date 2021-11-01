/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:48:24 by mykman            #+#    #+#             */
/*   Updated: 2021/11/01 23:14:01 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_printf("--------------------------------\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%5s\t|", (char *)stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf("     \t|");
		if (stack_b)
		{
			ft_printf("\t%s\n", (char *)stack_b->content);
			stack_b = stack_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("%5s\t|\t%s\n", "-", "-");
	ft_printf("%5s\t|\t%s\n", "A", "B");
}

int	main(int argc, char **argv)
{
	int		i;
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	t_dlist	*new;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (++i < argc)
	{
		new = ft_dlstnew(argv[i]);
		ft_dlstadd_back(&stack_a, new);
		if (!new)
			return (1);
	}
	print_stack(stack_a, stack_b);
	ft_rx(&stack_a);
	print_stack(stack_a, stack_b);
	ft_dlstclear(&stack_a, NULL);
	ft_dlstclear(&stack_b, NULL);
	return (0);
}
