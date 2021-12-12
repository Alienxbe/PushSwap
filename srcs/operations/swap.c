/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:24:09 by mykman            #+#    #+#             */
/*   Updated: 2021/11/12 02:33:49 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_data *data, t_stack *stack)
{
	int	tmp;

	tmp = stack->lst[stack->len - 1];
	stack->lst[stack->len - 1] = stack->lst[stack->len - 2];
	stack->lst[stack->len - 2] = tmp;
	add_operation(data, op_sa + stack->id);
}
