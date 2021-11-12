/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:23:55 by mykman            #+#    #+#             */
/*   Updated: 2021/11/12 02:51:44 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_data *data, t_stack *from, t_stack *to)
{
	if (!from->len)
		return ;
	to->lst[to->len++] = from->lst[from->len - 1];
	from->lst[from->len-- - 1] = 0;
	add_operation(data, op_pa + to->id);
}