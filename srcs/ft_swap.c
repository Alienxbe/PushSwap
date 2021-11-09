/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:04:04 by mykman            #+#    #+#             */
/*   Updated: 2021/11/09 15:13:40 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sx(t_stack *stack, t_bool output)
{
	t_dlist	*tmp;

	tmp = ft_dlstswap(*stack->first, (*stack->first)->next);
	if (tmp)
		*stack->first = tmp;
	if (tmp && output)
		ft_printf("s%c\n", stack->name);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b, t_bool output)
{
	ft_sx(stack_a, 0);
	ft_sx(stack_b, 0);
	if (output)
		ft_putendl_fd("ss", 1);
}
