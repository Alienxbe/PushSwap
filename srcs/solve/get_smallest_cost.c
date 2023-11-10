/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smallest_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:09:54 by marykman          #+#    #+#             */
/*   Updated: 2023/11/11 00:24:04 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "solve.h"
#include "moves.h"
#include "utils.h"

static int	same_rotate(t_fmove move_a, t_fmove move_b)
{
	return (((move_a == &ft_ra && move_b == &ft_rb)
		|| (move_a == &ft_rra && move_b == &ft_rrb)));
}

void	move_x_to_b(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b,
			t_dlist *element)
{
	t_dlist *max;
	t_fmove	move_a;
	t_fmove	move_b;

	if (!element)
		return ;
	max = ft_maxstack(*stack_b, *(int *)element->content);
	if (!max)
		max = ft_dlstmax(*stack_b);
	move_a = rotate_top_a(element);
	move_b = rotate_top_b(max);
	if (same_rotate(move_a, move_b))
	{
		while (*stack_a != element && *stack_b != max)
		{
			if (move_a == &ft_ra)
				ft_rr(moves, stack_a, stack_b);
			else
				ft_rrr(moves, stack_a, stack_b);
		}
	}
	while (move_a && *stack_a != element)
		move_a(moves, stack_a, stack_b);
	while (move_b && *stack_b != max)
		move_b(moves, stack_a, stack_b);
	ft_pb(moves, stack_a, stack_b);
}

t_dlist	*get_smallest_cost(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*move_tmp;
	t_dlist	*current;
	size_t	current_cost;
	t_dlist	*smallest;
	size_t	smallest_cost;

	current = *stack_a;
	move_tmp = NULL;
	smallest = NULL;
	while (current)
	{
		move_x_to_b(&move_tmp, stack_a, stack_b, current);
		current_cost = ft_dlstsize(move_tmp, move_tmp->next);
		if (!smallest || current_cost < smallest_cost)
		{
			smallest = current;
			smallest_cost = current_cost;
		}
		ft_reverse_moves(&move_tmp, stack_a, stack_b);
		current = current->next;
	}
	return (smallest);
}
