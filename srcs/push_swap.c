/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:48:24 by mykman            #+#    #+#             */
/*   Updated: 2021/12/12 12:54:30 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (set_data(argc, argv, &data))
		ft_error(data);
	if (issorted(data.a.lst, data.a.len - 1, -1))
		ft_exit(data, EXIT_SUCCESS);
	print_stack(data, argc);
	push(&data, &data.a, &data.b);
	print_stack(data, argc);
	ft_lstiter(data.operations, &print_operation);
	ft_exit(data, EXIT_SUCCESS);
}
