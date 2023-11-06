/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:11:00 by marykman          #+#    #+#             */
/*   Updated: 2023/11/06 23:55:39 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "push_swap.h"

static t_dlist	*get_after(t_dlist **stack, int min_value)
{
	t_dlist	*current;
	t_dlist	*min;

	min = NULL;
	current = *stack;
	while (current)
	{
		if ((!min || *(int *)current->content < *(int *)min->content)
			&& *(int *)current->content > min_value)
			min = current;
		current = current->next;
	}
	return (min);
}

static size_t	rotate_top_cost(t_dlist *element)
{
	size_t	rotate_cost;
	size_t	rrotate_cost;

	if (!element)
		return (0);
	rotate_cost = ft_dlstsize(element, element->next); // Element count toward the end
	rrotate_cost = ft_dlstsize(element, element->previous) - 1; // Toward start
	if (rotate_cost < rrotate_cost)
		return (rotate_cost);
	return (rrotate_cost);
}

size_t	get_cost(t_dlist **stack_a, t_dlist **stack_b, t_dlist *element)
{
	size_t	cost;
	t_dlist	*after;

	(void)stack_a;
	cost = rotate_top_cost(element); // Cost for rotating A
	after = get_after(stack_b, *(int *)element->content);
	if (!after)
		after = ft_dlstmin(*stack_b);
	cost += rotate_top_cost(after); // Cost for Rotating B
	cost++; // Cost for push
	return (cost);
}
