/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:54:23 by marykman          #+#    #+#             */
/*   Updated: 2023/11/11 00:22:49 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <stddef.h>
# include "ft_dlist.h"

// Sorting functions

t_dlist	*crap_sort(t_dlist **stack_a, t_dlist **stack_b);
t_dlist	*cost_sort(t_dlist **stack_a, t_dlist **stack_b);

// Utility functions

t_dlist	*ft_minstack(t_dlist *stack, int bottom_value);
t_dlist	*ft_maxstack(t_dlist *stack, int top_value);
size_t	get_cost(t_dlist **stack_a, t_dlist **stack_b, t_dlist *element);
t_dlist	*get_smallest_cost(t_dlist **stack_a, t_dlist **stack_b);
void	move_x_to_b(t_dlist **moves, t_dlist **stack_a, t_dlist **stack_b,
			t_dlist *element);

#endif
