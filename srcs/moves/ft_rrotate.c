/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:05:54 by mykman            #+#    #+#             */
/*   Updated: 2023/11/10 22:14:32 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_string.h"
#include "moves.h"

void	ft_rrx(t_dlist **moves, t_dlist **stack, char *name)
{
	ft_dlstadd_front(stack, ft_dlstremove_back(stack));
	if (name)
		ft_dlstadd_back(moves, ft_dlstnew(name));
}

void	ft_rra(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	(void)stack_b;
	ft_rrx(moves, stack_a, MOVE_RRA_STR);
}

void	ft_rrb(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	(void)stack_a;
	ft_rrx(moves, stack_b, MOVE_RRB_STR);
}

void	ft_rrr(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rrx(moves, stack_a, NULL);
	ft_rrx(moves, stack_b, NULL);
	ft_dlstadd_back(moves, ft_dlstnew(MOVE_RRR_STR));
}
