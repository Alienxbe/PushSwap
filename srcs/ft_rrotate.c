/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:05:54 by mykman            #+#    #+#             */
/*   Updated: 2021/11/09 15:23:05 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrx(t_stack *stack, t_bool output)
{
	ft_dlstadd_front(stack->first, ft_dlstremove_back(stack->first));
	if (output)
		ft_printf("rr%c\n", stack->name);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b, t_bool output)
{
	ft_rrx(stack_a, 0);
	ft_rrx(stack_b, 0);
	if (output)
		ft_putendl_fd("rrr", 1);
}
