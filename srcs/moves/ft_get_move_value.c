/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_move_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:01:33 by marykman          #+#    #+#             */
/*   Updated: 2023/11/10 20:45:09 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

t_move	ft_get_move_value(char *move)
{
	t_move	index;
	char	**moves;

	moves = (char *[MOVE_LEN]){
		MOVE_SA_STR,
		MOVE_SB_STR,
		MOVE_SS_STR,
		MOVE_PA_STR,
		MOVE_PB_STR,
		MOVE_RA_STR,
		MOVE_RB_STR,
		MOVE_RR_STR,
		MOVE_RRA_STR,
		MOVE_RRB_STR,
		MOVE_RRR_STR
	};
	index = -1;
	while (++index < MOVE_LEN)
		if (move == moves[index])
			return (index);
	return (MOVE_ERROR);
}
