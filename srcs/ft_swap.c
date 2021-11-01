/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:04:04 by mykman            #+#    #+#             */
/*   Updated: 2021/11/01 23:13:18 by mykman           ###   ########.fr       */
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
