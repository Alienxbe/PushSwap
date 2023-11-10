/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:17:15 by marykman          #+#    #+#             */
/*   Updated: 2023/11/10 22:06:12 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "ft_dlist.h"

// Defining constants

# define MOVE_SA_STR	"sa"
# define MOVE_SB_STR	"sb"
# define MOVE_SS_STR	"ss"
# define MOVE_PA_STR	"pa"
# define MOVE_PB_STR	"pb"
# define MOVE_RA_STR	"ra"
# define MOVE_RB_STR	"rb"
# define MOVE_RR_STR	"rr"
# define MOVE_RRA_STR	"rra"
# define MOVE_RRB_STR	"rrb"
# define MOVE_RRR_STR	"rrr"

// Typedefs

typedef enum e_move
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	MOVE_LEN,
	MOVE_ERROR
}	t_move;
typedef void	(*t_fmove)(t_dlist **, t_dlist **, t_dlist **);

// Functions

void	ft_sa(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);
void	ft_sb(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);
void	ft_ss(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);
void	ft_pa(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);
void	ft_pb(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);
void	ft_ra(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);
void	ft_rb(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);
void	ft_rr(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);
void	ft_rra(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);
void	ft_rrb(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);
void	ft_rrr(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);

t_fmove	rotate_top_a(t_dlist *element);
t_fmove	rotate_top_b(t_dlist *element);

void	ft_move(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b, t_move move);
void	ft_reverse_moves(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b);
t_move	ft_get_move_value(char *move);

#endif
