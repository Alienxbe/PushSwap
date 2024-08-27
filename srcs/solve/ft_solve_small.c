/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:24:56 by marykman          #+#    #+#             */
/*   Updated: 2024/08/27 18:47:36 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include "solve.h"

static int	get_case(int a, int b, int c)
{
	if (a < c && c < b)
		return (RROTATE_SWAP);
	if (b < a && a < c)
		return (SWAP);
	if (b < c && c < a)
		return (SORTED_R);
	if (c < a && a < b)
		return (SORTED_RR);
	if (c < b && b < a)
		return (SWAP_ROTATE);
	return (SORTED);
}

void	small_sort(t_dlist **stack_a, t_dlist **moves)
{
	t_case	c;

	if (!(*stack_a)->next->next)
	{
		ft_sa(moves, stack_a, NULL);
		return ;
	}
	c = get_case(*(int *)(*stack_a)->content,
			*(int *)(*stack_a)->next->content,
			*(int *)(*stack_a)->next->next->content);
	if (c == RROTATE_SWAP)
		ft_rra(moves, stack_a, NULL);
	if (c == SWAP || c == RROTATE_SWAP || c == SWAP_ROTATE)
		ft_sa(moves, stack_a, NULL);
	if (c == SORTED_R)
		ft_ra(moves, stack_a, NULL);
	if (c == SORTED_RR || c == SWAP_ROTATE)
		ft_rra(moves, stack_a, NULL);
}
