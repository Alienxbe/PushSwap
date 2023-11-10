/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:59:57 by marykman          #+#    #+#             */
/*   Updated: 2023/11/10 17:57:20 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_dlist.h"

/**
 * @brief Function that find the lowest value in the stack given while
 * being greater than `bottom_value`
 * 
 * @param stack Stack used for the calculation
 * @param bottom_value Nothing below this value will be returned
 * @return The lowes value found in the stack wich is not below `bottom_value`
 */
t_dlist	*ft_minstack(t_dlist *stack, int bottom_value)
{
	t_dlist *min;
	
	min = NULL;
	while (stack)
	{
		if ((!min || *(int *)stack->content < *(int *)min->content)
			&& *(int *)stack->content > bottom_value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
