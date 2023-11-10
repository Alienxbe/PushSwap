/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:47:27 by marykman          #+#    #+#             */
/*   Updated: 2023/11/10 21:46:36 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "moves.h"

static t_move	get_opposite_move(t_move move)
{
	t_move	*moves;

	moves = (t_move [MOVE_LEN]){
		SA,
		SB,
		SS,
		PB,
		PA,
		RRA,
		RRB,
		RRR,
		RA,
		RB,
		RR
	};
	return (moves[move]);
}

void	ft_reverse_moves(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*current;
	t_move	move;

	current = ft_dlstlast(*moves);
	while (current)
	{
		move = ft_get_move_value((char *)current->content);
		if (move == MOVE_ERROR)
			return ;
		move = get_opposite_move(move);
		ft_move(NULL, stack_a, stack_b, move);
		current = current->previous;
		free(ft_dlstremove_back(moves));
	}
}
