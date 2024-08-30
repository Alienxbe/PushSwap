/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:04:04 by mykman            #+#    #+#             */
/*   Updated: 2024/08/30 23:34:15 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "moves.h"

static void	ft_sx(t_dlist **moves, t_dlist **stack, char *name)
{
	t_dlist	*tmp;

	if (!*stack)
		return ;
	tmp = ft_dlstswap(*stack, (*stack)->next);
	if (tmp)
		*stack = tmp;
	if (tmp && name)
		ft_dlstadd_back(moves, ft_dlstnew(name));
}

void	ft_sa(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	(void)stack_b;
	ft_sx(moves, stack_a, MOVE_SA_STR);
}

void	ft_sb(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	(void)stack_a;
	ft_sx(moves, stack_b, MOVE_SB_STR);
}

void	ft_ss(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	ft_sx(moves, stack_a, NULL);
	ft_sx(moves, stack_b, NULL);
	ft_dlstadd_back(moves, ft_dlstnew(MOVE_SS_STR));
}
