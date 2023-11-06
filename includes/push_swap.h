/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:06:45 by mykman            #+#    #+#             */
/*   Updated: 2023/11/07 00:03:09 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "ft_dlist.h"


/*
** MAIN FUNCTIONS
*/

void	ft_sx(t_dlist **stack, char *text);
void	ft_ss(t_dlist **stack_a, t_dlist **stack_b);
void	ft_px(t_dlist **stack_from, t_dlist **stack_to, char *text);
void	ft_rx(t_dlist **stack, char *text);
void	ft_rr(t_dlist **stack_a, t_dlist **stack_b);
void	ft_rrx(t_dlist **stack, char *text);
void	ft_rrr(t_dlist **stack_a, t_dlist **stack_b);

void	rotate_top(t_dlist **stack, t_dlist *elem);

void	crap_sort(t_dlist **stack_a, t_dlist **stack_b);
void	cost_sort(t_dlist **stack_a, t_dlist **stack_b);

size_t	get_cost(t_dlist **stack_a, t_dlist **stack_b, t_dlist *element);


/*
** UTILS
*/

t_dlist	*fill_stack(int argc, char **argv, int **content);

int		is_sorted(t_dlist *stack);

void	print_stack(t_dlist *stack_a, t_dlist *stack_b);


#endif