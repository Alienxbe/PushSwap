/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:24:06 by mykman            #+#    #+#             */
/*   Updated: 2021/12/15 12:50:39 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_data *data, t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->len < 2)
		return ;
	i = stack->len;
	tmp = stack->lst[i - 1];
	while (--i > 0)
		stack->lst[i] = stack->lst[i - 1];
	stack->lst[0] = tmp;
	if (!data->checker_mode)
		add_operation(data, op_ra + stack->id);
}

void	ra(t_data *data)
{
	rotate(data, &data->a);
}

void	rb(t_data *data)
{
	rotate(data, &data->b);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
