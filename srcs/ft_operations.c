/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:05:54 by mykman            #+#    #+#             */
/*   Updated: 2021/11/01 19:00:32 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sx(t_dlist **stack)
{
	t_dlist	*tmp;

	tmp = ft_dlstswap(*stack, (*stack)->next);
	if (tmp)
		*stack = tmp;
}

void	ft_ss(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_sx(stack_a);
	ft_sx(stack_b);
}

void	ft_px(t_dlist **stack_from, t_dlist **stack_to)
{
	ft_dlstadd_front(stack_to, ft_dlstremove_front(stack_from));
}

void	ft_rx(t_dlist **stack)
{
	ft_dlstadd_back(stack, ft_dlstremove_front(stack));
}

void	ft_rr(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rx(stack_a);
	ft_rx(stack_b);
}

void	ft_rrx(t_dlist **stack)
{
	ft_dlstadd_front(stack, ft_dlstremove_back(stack));
}

void	ft_rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rrx(stack_a);
	ft_rrx(stack_b);
}