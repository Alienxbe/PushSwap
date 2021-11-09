/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:06:45 by mykman            #+#    #+#             */
/*   Updated: 2021/11/09 23:27:37 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/includes/libft.h"

typedef unsigned char	t_bool;

typedef struct s_stack
{
	t_dlist	**first;
	char	name;
}						t_stack;


/*
** MAIN FUNCTIONS
*/

void	ft_sx(t_stack *stack, t_bool output);
void	ft_rx(t_stack *stack, t_bool output);
void	ft_rrx(t_stack *stack, t_bool output);
void	ft_px(t_stack *stack_from, t_stack *stack_to, t_bool output);
void	ft_ss(t_stack *stack_a, t_stack *stack_b, t_bool output);
void	ft_rr(t_stack *stack_a, t_stack *stack_b, t_bool output);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b, t_bool output);

void	rotate_top(t_stack *stack, t_dlist *elem, t_bool output);

void	ft_sort(t_stack *stack_a, t_stack *stack_b, t_bool outpur);


/*
** UTILS
*/

t_dlist	**fill_stack(int argc, char **argv, int **content);

int		is_sorted(t_dlist *stack);
int		in_list(int *list, int index, int n);

void	print_stack(t_dlist *stack_a, t_dlist *stack_b);


#endif