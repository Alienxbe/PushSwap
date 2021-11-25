/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:14:47 by mykman            #+#    #+#             */
/*   Updated: 2021/11/25 14:17:26 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(int *lst, int start, int end)
{
	int	direction;
	int	prev;

	direction = 1;
	prev = lst[start];
	if (end < start)
		direction = -1;
	while (start != end)
	{
		if (prev > lst[start])
			return (0);
		prev = lst[start];
		start += direction;
	}
	return (1);
}