/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:59:08 by mykman            #+#    #+#             */
/*   Updated: 2021/12/13 16:26:44 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_operation(t_data *data, int op_id)
{
	t_list	*new;

	new = ft_lstnew(data->op_list + op_id);
	if (!new)
		ft_exit(*data, 1);
	ft_lstadd_back(&data->operations, new);
}
