/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:00:04 by mykman            #+#    #+#             */
/*   Updated: 2024/08/27 18:41:26 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static void	ft_init_table(t_fmove *fmove)
{
	fmove[SA] = &ft_sa;
	fmove[SB] = &ft_sb;
	fmove[SS] = &ft_ss;
	fmove[PA] = &ft_pa;
	fmove[PB] = &ft_pb;
	fmove[RA] = &ft_ra;
	fmove[RB] = &ft_rb;
	fmove[RR] = &ft_rr;
	fmove[RRA] = &ft_rra;
	fmove[RRB] = &ft_rrb;
	fmove[RRR] = &ft_rrr;
}

void	ft_move(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b,
			t_move move)
{
	t_fmove	fmove[MOVE_LEN];

	ft_init_table(fmove);
	fmove[move](moves, stack_a, stack_b);
}
