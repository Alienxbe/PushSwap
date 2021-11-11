/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:06:45 by mykman            #+#    #+#             */
/*   Updated: 2021/11/11 23:21:39 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/includes/libft.h"


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


/*
** UTILS
*/

t_dlist	*fill_stack(int argc, char **argv, int **content);

int		is_sorted(t_dlist *stack);
int		in_list(int *list, int index, int n);

void	print_stack(t_dlist *stack_a, t_dlist *stack_b);


#endif