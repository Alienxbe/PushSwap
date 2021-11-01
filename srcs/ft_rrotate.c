/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:05:54 by mykman            #+#    #+#             */
/*   Updated: 2021/11/01 23:13:14 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrx(t_dlist **stack)
{
	ft_dlstadd_front(stack, ft_dlstremove_back(stack));
}

void	ft_rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rrx(stack_a);
	ft_rrx(stack_b);
}
