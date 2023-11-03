/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:35:50 by mykman            #+#    #+#             */
/*   Updated: 2023/11/03 17:05:49 by marykman         ###   ########.fr       */
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

void	crap_sort(t_dlist **stack_a, t_dlist **stack_b)
{
	while (*stack_a)
	{
		rotate_top(stack_a, ft_dlstmin(*stack_a));
		if (is_sorted(*stack_a))
			break ;
		ft_px(stack_a, stack_b, "pb");
	}
	while (*stack_b)
	{
		ft_px(stack_b, stack_a, "pa");
	}
}