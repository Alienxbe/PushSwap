/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:33:44 by mykman            #+#    #+#             */
/*   Updated: 2021/12/12 17:33:44 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(void *content)
{
	static char	*op_text[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};

	ft_printf("%s\n", op_text[*(int *)content]);
}

void	print_stack(t_data data, int argc)
{
	int	i;

	ft_printf("Stack a len : %d, stack b len : %d\n", data.a.len, data.b.len);
	i = argc - 1;
	while (--i > -1)
	{
		ft_printf("%d: %d | %d\n", i, data.a.lst[i], data.b.lst[i]);
	}
}
