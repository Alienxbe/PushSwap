/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:05:14 by mykman            #+#    #+#             */
/*   Updated: 2023/11/02 15:57:31 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	ft_px(t_dlist **stack_from, t_dlist **stack_to, char *text)
{
	ft_dlstadd_front(stack_to, ft_dlstremove_front(stack_from));
	if (text)
		ft_printf("%s\n", text);
}
