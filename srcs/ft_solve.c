/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:35:50 by mykman            #+#    #+#             */
/*   Updated: 2021/11/08 16:26:56 by mykman           ###   ########.fr       */
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

void	rotate_top(t_dlist **stack, t_dlist *elem)
{
	int	move_up;
	int	move_down;

	move_up = ft_dlstsize(elem, elem->previous);
	move_down = ft_dlstsize(elem, elem->next) + 1;
	while (*stack != elem)
	{
		if (move_up <= move_down)
			ft_rx(stack, "ra");
		else
			ft_rrx(stack, "rra");
	}
}

void	ft_sort(t_dlist **stack_a, t_dlist **stack_b)
{
	while (*stack_a)
	{
		rotate_top(stack_a, ft_dlstmin(*stack_a));
		if (is_sorted(*stack_a))
			break ;
		ft_px(stack_a, stack_b, "pb");
	}
	while (*stack_b)
		ft_px(stack_b, stack_a, "pa");
}