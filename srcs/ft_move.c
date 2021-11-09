/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:38:04 by mykman            #+#    #+#             */
/*   Updated: 2021/11/09 15:18:02 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_top(t_stack *stack, t_dlist *elem, t_bool output)
{
	int	move_up;
	int	move_down;

	move_up = ft_dlstsize(elem, elem->previous);
	move_down = ft_dlstsize(elem, elem->next) + 1;
	while (*stack->first != elem)
	{
		if (move_up <= move_down)
			ft_rx(stack, output);
		else
			ft_rrx(stack, output);
	}
}