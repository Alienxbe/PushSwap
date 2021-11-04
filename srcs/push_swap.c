/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:48:24 by mykman            #+#    #+#             */
/*   Updated: 2021/11/04 17:27:30 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_return(int value, t_dlist *stack, int *content)
{
	if (content)
		free(content);
	if (stack)
		ft_dlstclear(&stack, NULL);
	return (value);
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	int		*content;

	if (argc < 2)
		return (1);
	content = NULL;
	stack_a = fill_stack(argc, argv, &content);
	stack_b = NULL;
	if (!stack_a || is_sorted(stack_a))
		return (free_return(1, stack_a, content));
	print_stack(stack_a, stack_b);
	ft_px(&stack_a, &stack_b, "pb");
	ft_sx(&stack_a, "sa");
	print_stack(stack_a, stack_b);
	ft_dlstclear(&stack_a, NULL);
	ft_dlstclear(&stack_b, NULL);
	return (0);
}
