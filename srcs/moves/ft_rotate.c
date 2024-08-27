/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:06:46 by mykman            #+#    #+#             */
/*   Updated: 2024/08/27 19:38:55 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "moves.h"

static void	ft_rx(t_dlist **moves, t_dlist **stack, char *name)
{
	ft_dlstadd_back(stack, ft_dlstremove_front(stack));
	if (name)
		ft_dlstadd_back(moves, ft_dlstnew(name));
}

void	ft_ra(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	(void)stack_b;
	ft_rx(moves, stack_a, MOVE_RA_STR);
}

void	ft_rb(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	(void)stack_a;
	ft_rx(moves, stack_b, MOVE_RB_STR);
}

void	ft_rr(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rx(moves, stack_a, NULL);
	ft_rx(moves, stack_b, NULL);
	ft_dlstadd_back(moves, ft_dlstnew(MOVE_RR_STR));
}
