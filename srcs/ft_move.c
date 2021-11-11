/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:00:04 by mykman            #+#    #+#             */
/*   Updated: 2021/11/11 21:00:20 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_top(t_dlist **stack, t_dlist *elem)
{
	int	move_up;
	int	move_down;

	move_up = ft_dlstsize(elem, elem->previous);
	move_down = ft_dlstsize(elem, elem->next) + 1;
	while (*stack != elem)
	{
		if (move_up <= move_down)
			ft_rx(stack, "ra");
		else
			ft_rrx(stack, "rra");
	}
}