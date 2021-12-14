/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:24:01 by mykman            #+#    #+#             */
/*   Updated: 2021/12/14 11:48:53 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_data *data, t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->lst[0];
	while (++i < stack->len - 1)
		stack->lst[i] = stack->lst[i + 1];
	stack->lst[stack->len - 1] = tmp;
	add_operation(data, op_rra + stack->id);
}