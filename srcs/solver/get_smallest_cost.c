/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smallest_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:09:54 by marykman          #+#    #+#             */
/*   Updated: 2024/08/27 19:38:41 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include "moves.h"
#include "utils.h"

static int	same_rotate(t_fmove move_a, t_fmove move_b)
{
	return (((move_a == &ft_ra && move_b == &ft_rb)
			|| (move_a == &ft_rra && move_b == &ft_rrb)));
}

static void	rotate_same_direction(t_dlist **moves, t_dlist **stack_a,
			t_dlist **stack_b, t_dlist *element)
{
	t_dlist	*max;
	t_fmove	move_a;

	max = ft_maxstack(*stack_b, *(int *)element->content);
	if (!max)
		max = ft_dlstmax(*stack_b);
	move_a = rotate_top_a(element);
	while (*stack_a != element && *stack_b != max)
	{
		if (move_a == &ft_ra)
			ft_rr(moves, stack_a, stack_b);
		else
			ft_rrr(moves, stack_a, stack_b);
	}
}

void	move_x_to_b(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b,
			t_dlist *element)
{
	t_dlist	*max;
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
		rotate_same_direction(moves, stack_a, stack_b, element);
	while (*stack_a && *stack_a != element)
		move_a(moves, stack_a, stack_b);
	while (*stack_b && *stack_b != max)
		move_b(moves, stack_a, stack_b);
	ft_pb(moves, stack_a, stack_b);
}

void	move_x_to_a(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b,
			t_dlist *element)
{
	t_dlist	*min;
	t_fmove	move_a;

	if (!element)
		return ;
	min = ft_minstack(*stack_a, *(int *)element->content);
	if (!min)
		min = ft_dlstmin(*stack_a);
	move_a = rotate_top_a(min);
	while (*stack_a && *stack_a != min)
		move_a(moves, stack_a, stack_b);
	ft_pa(moves, stack_a, stack_b);
}

t_dlist	*get_smallest_cost(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*current;
	t_dlist	*smallest;
	size_t	smallest_cost;
	size_t	calc;

	current = *stack_a;
	smallest = NULL;
	while (current)
	{
		calc = get_cost(stack_a, stack_b, current);
		if (!smallest || calc < smallest_cost)
		{
			smallest = current;
			smallest_cost = calc;
		}
		current = current->next;
	}
	return (smallest);
}
