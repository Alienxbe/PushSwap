/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:06:46 by mykman            #+#    #+#             */
/*   Updated: 2023/11/02 16:04:50 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "push_swap.h"

void	ft_rx(t_dlist **stack, char *text)
{
	ft_dlstadd_back(stack, ft_dlstremove_front(stack));
	if (text)
		ft_printf("%s\n", text);
}

void	ft_rr(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rx(stack_a, NULL);
	ft_rx(stack_b, NULL);
	ft_printf("rr\n");
}
