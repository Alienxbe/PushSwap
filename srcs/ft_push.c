/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:05:14 by mykman            #+#    #+#             */
/*   Updated: 2021/11/09 15:22:07 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_px(t_stack *stack_from, t_stack *stack_to, t_bool output)
{
	ft_dlstadd_front(stack_to->first, ft_dlstremove_front(stack_from->first));
	if (output)
		ft_printf("p%c\n", stack_to->name);
}
