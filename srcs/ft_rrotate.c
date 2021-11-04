/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:05:54 by mykman            #+#    #+#             */
/*   Updated: 2021/11/04 17:20:22 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrx(t_dlist **stack, char *text)
{
	ft_dlstadd_front(stack, ft_dlstremove_back(stack));
	if (text)
		ft_putendl_fd(text, 1);
}

void	ft_rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rrx(stack_a, NULL);
	ft_rrx(stack_b, NULL);
	ft_putendl_fd("rrr", 1);
}
