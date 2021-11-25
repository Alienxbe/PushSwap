/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:48:24 by mykman            #+#    #+#             */
/*   Updated: 2021/11/25 14:22:43 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_operation(void *content)
{
	static char	*op_text[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
										"rb", "rr", "rra", "rrb", "rrr"};

	ft_printf("%s\n", op_text[*(int *)content]);
}

static void	print_stack(t_data data, int argc)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
	{
		ft_printf("%d: %d | %d\n", i, data.a.lst[argc - i - 2], data.b.lst[argc - i - 2]);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (set_data(argc, argv, &data))
		ft_exit(data, 1);
	if (issorted(data.a.lst, data.a.len - 1, -1))
		ft_exit(data, 1);
	print_stack(data, argc);
	ft_lstiter(data.operations, &print_operation);
	ft_exit(data, 0);
}
