/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:48:24 by mykman            #+#    #+#             */
/*   Updated: 2021/11/09 23:31:01 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int	free_return(int value, t_dlist *stack, int *content)
{
	if (content)
		free(content);
	if (stack)
		ft_dlstclear(&stack, NULL);
	return (value);
}*/

static t_stack	*new_stack(t_dlist **first, char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->first = first;
	stack->name = name;
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*content;

	if (argc < 2)
		return (1);
	content = NULL;
	stack_a = new_stack(fill_stack(argc, argv, &content), 'a');
	stack_b = new_stack(NULL, 'b');
	ft_printf("a: %p | b: %p | a->first: %p", stack_a, stack_b, stack_a->first);
	if (!stack_a || !stack_b || !stack_a->first || is_sorted(*stack_a->first))
	{
		ft_printf("EXITING : %p\n", *stack_a->first);
		exit(1);
	}
	print_stack(*stack_a->first, *stack_b->first);
	//ft_sort(stack_a, stack_b, 1);
	print_stack(*stack_a->first, *stack_b->first);
	ft_dlstclear(stack_a->first, NULL);
	ft_dlstclear(stack_b->first, NULL);
	free(content);
	free(stack_a);
	free(stack_b);
	return (0);
}
