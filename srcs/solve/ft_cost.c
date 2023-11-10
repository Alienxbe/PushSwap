/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:11:00 by marykman          #+#    #+#             */
/*   Updated: 2023/11/10 20:06:28 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

// static size_t	rotate_top_cost(t_dlist *element)
// {
// 	size_t	rotate_cost;
// 	size_t	rrotate_cost;

// 	if (!element)
// 		return (0);
// 	rotate_cost = ft_dlstsize(element, element->next); // Element count toward the end
// 	rrotate_cost = ft_dlstsize(element, element->previous) - 1; // Toward start
// 	if (rotate_cost < rrotate_cost)
// 		return (rotate_cost);
// 	return (rrotate_cost);
// }

size_t	get_cost(t_dlist **stack_a, t_dlist **stack_b, t_dlist *element)
{
	// size_t	cost;
	// t_dlist	*after;

	(void)stack_a;
	(void)stack_b;
	(void)element;
	// cost = rotate_top_cost(element); // Cost for rotating A
	// after = get_after(stack_b, *(int *)element->content);
	// if (!after)
	// 	after = ft_dlstmin(*stack_b);
	// if (after)
	// 	ft_printf("After cost: %d\n", *(int *)after->content);
	// cost += rotate_top_cost(after); // Cost for Rotating B
	// cost++; // Cost for push
	// return (cost);
	return (0);
}
