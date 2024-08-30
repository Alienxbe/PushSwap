/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:17:22 by marykman          #+#    #+#             */
/*   Updated: 2024/08/27 18:42:22 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "moves.h"

t_fmove	rotate_top_a(t_dlist *element)
{
	if (!element)
		return (NULL);
	if (ft_dlstsize(element, element->next) + 1
		< ft_dlstsize(element, element->previous))
		return (&ft_rra);
	return (&ft_ra);
}

t_fmove	rotate_top_b(t_dlist *element)
{
	if (!element)
		return (NULL);
	if (ft_dlstsize(element, element->next) + 1
		< ft_dlstsize(element, element->previous))
		return (&ft_rrb);
	return (&ft_rb);
}
