/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:05:54 by mykman            #+#    #+#             */
/*   Updated: 2023/11/02 16:04:20 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "push_swap.h"

void	ft_rrx(t_dlist **stack, char *text)
{
	ft_dlstadd_front(stack, ft_dlstremove_back(stack));
	if (text)
		ft_printf("%s\n", text);
}

void	ft_rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rrx(stack_a, NULL);
	ft_rrx(stack_b, NULL);
	ft_printf("rrr\n");
}
