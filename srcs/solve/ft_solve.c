/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:35:50 by mykman            #+#    #+#             */
/*   Updated: 2024/08/27 19:38:47 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_dlist.h"
#include "moves.h"
#include "utils.h"
#include "solve.h"

t_dlist	*crap_sort(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*moves;

	moves = NULL;
	while (!is_sorted(*stack_a))
	{
		while (*stack_a != ft_dlstmin(*stack_a))
			rotate_top_a(ft_dlstmin(*stack_a))(&moves, stack_a, stack_b);
		if (!is_sorted(*stack_a))
			ft_pb(&moves, stack_a, stack_b);
	}
	while (*stack_b)
		ft_pa(&moves, stack_a, stack_b);
	return (moves);
}

t_dlist	*cost_sort(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*moves;
	t_dlist	*smallest;

	moves = NULL;
	while (*stack_a && (*stack_a)->next
		&& (*stack_a)->next->next
		&& (*stack_a)->next->next->next)
	{
		smallest = get_smallest_cost(stack_a, stack_b);
		move_x_to_b(&moves, stack_a, stack_b, smallest);
	}
	while (*stack_b != ft_dlstmax(*stack_b))
		rotate_top_b(ft_dlstmax(*stack_b))(&moves, stack_a, stack_b);
	small_sort(stack_a, &moves);
	while (*stack_b)
		move_x_to_a(&moves, stack_a, stack_b, *stack_b);
	while (*stack_a != ft_dlstmin(*stack_a))
		rotate_top_a(ft_dlstmin(*stack_a))(&moves, stack_a, stack_b);
	return (moves);
}
