/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:06:46 by mykman            #+#    #+#             */
/*   Updated: 2021/11/09 15:22:31 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(t_stack *stack, t_bool output)
{
	ft_dlstadd_back(stack->first, ft_dlstremove_front(stack->first));
	if (output)
		ft_printf("r%c\n", stack->name);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b, t_bool output)
{
	ft_rx(stack_a, 0);
	ft_rx(stack_b, 0);
	if (output)
		ft_putendl_fd("rr", 1);
}
