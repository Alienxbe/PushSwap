/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:23:55 by mykman            #+#    #+#             */
/*   Updated: 2021/12/15 12:48:57 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_data *data, t_stack *from, t_stack *to)
{
	if (!from->len)
		return ;
	to->lst[to->len++] = from->lst[from->len - 1];
	from->lst[from->len-- - 1] = 0;
	if (!data->checker_mode)
		add_operation(data, op_pa + to->id);
}

void	pa(t_data *data)
{
	push(data, &data->b, &data->a);
}

void	pb(t_data *data)
{
	push(data, &data->a, &data->b);
}
