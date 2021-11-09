/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:35:50 by mykman            #+#    #+#             */
/*   Updated: 2021/11/09 15:24:17 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_dlist *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b, t_bool output)
{
	while (*stack_a->first)
	{
		rotate_top(stack_a, ft_dlstmin(*stack_a->first), output);
		if (is_sorted(*stack_a->first))
			break ;
		ft_px(stack_a, stack_b, output);
	}
	while (*stack_b->first)
		ft_px(stack_b, stack_a, output);
}