/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:06:46 by mykman            #+#    #+#             */
/*   Updated: 2021/11/01 23:13:10 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(t_dlist **stack)
{
	ft_dlstadd_back(stack, ft_dlstremove_front(stack));
}

void	ft_rr(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rx(stack_a);
	ft_rx(stack_b);
}
