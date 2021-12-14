/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:24:06 by mykman            #+#    #+#             */
/*   Updated: 2021/12/13 16:05:07 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_data *data, t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->len;
	tmp = stack->lst[i - 1];
	while (--i > 0)
		stack->lst[i] = stack->lst[i - 1];
	stack->lst[0] = tmp;
	add_operation(data, op_ra + stack->id);
}