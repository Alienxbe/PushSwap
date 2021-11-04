/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:05:14 by mykman            #+#    #+#             */
/*   Updated: 2021/11/04 17:17:41 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_px(t_dlist **stack_from, t_dlist **stack_to, char *text)
{
	ft_dlstadd_front(stack_to, ft_dlstremove_front(stack_from));
	if (text)
		ft_putendl_fd(text, 1);
}
