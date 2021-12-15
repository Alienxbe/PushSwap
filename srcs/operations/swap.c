/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:24:09 by mykman            #+#    #+#             */
/*   Updated: 2021/12/15 12:52:14 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_data *data, t_stack *stack)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->lst[stack->len - 1];
	stack->lst[stack->len - 1] = stack->lst[stack->len - 2];
	stack->lst[stack->len - 2] = tmp;
	add_operation(data, op_sa + stack->id);
}


void	sa(t_data *data)
{
	swap(data, &data->a);
}

void	sb(t_data *data)
{
	swap(data, &data->b);
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
