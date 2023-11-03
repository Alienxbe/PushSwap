/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:04:04 by mykman            #+#    #+#             */
/*   Updated: 2023/11/02 16:04:38 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "push_swap.h"

void	ft_sx(t_dlist **stack, char *text)
{
	t_dlist	*tmp;

	tmp = ft_dlstswap(*stack, (*stack)->next);
	if (tmp)
		*stack = tmp;
	if (tmp && text)
		ft_printf("%s\n", text);
}

void	ft_ss(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_sx(stack_a, NULL);
	ft_sx(stack_b, NULL);
	ft_printf("ss\n");
}
