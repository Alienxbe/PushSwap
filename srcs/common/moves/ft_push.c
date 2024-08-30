/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:05:14 by mykman            #+#    #+#             */
/*   Updated: 2024/08/30 23:59:31 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static void	ft_px(t_dlist **moves, t_dlist **stack_from, t_dlist **stack_to,
				char *name)
{
	t_dlist	*element;

	element = ft_dlstremove_front(stack_from);
	if (element)
		ft_dlstadd_front(stack_to, element);
	if (name)
		ft_dlstadd_back(moves, ft_dlstnew(name));
}

void	ft_pa(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	ft_px(moves, stack_b, stack_a, MOVE_PA_STR);
}

void	ft_pb(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	ft_px(moves, stack_a, stack_b, MOVE_PB_STR);
}
