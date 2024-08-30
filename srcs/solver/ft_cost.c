/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:11:00 by marykman          #+#    #+#             */
/*   Updated: 2024/08/30 18:39:45 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "utils.h"
#include "solve.h"

static size_t	rotate_top_cost(t_dlist *element)
{
	size_t	rotate_cost;
	size_t	rrotate_cost;

	if (!element)
		return (0);
	rotate_cost = ft_dlstsize(element, element->next);
	rrotate_cost = ft_dlstsize(element, element->previous) - 1;
	if (rotate_cost < rrotate_cost)
		return (rotate_cost);
	return (-rrotate_cost);
}

size_t	get_cost(t_dlist **stack_a, t_dlist **stack_b, t_dlist *element)
{
	size_t	cost;
	size_t	cost_a;
	size_t	cost_b;
	t_dlist	*after;

	(void)stack_a;
	cost_a = rotate_top_cost(element);
	after = ft_maxstack(*stack_b, *(int *)element->content);
	if (!after)
		after = ft_dlstmax(*stack_b);
	cost_b = rotate_top_cost(after);
	cost = ft_abs(cost_a) + ft_abs(cost_b) + 1;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
		cost -= ft_minint(ft_abs(cost_a), ft_abs(cost_b));
	return (cost);
}
