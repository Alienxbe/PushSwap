/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:48:24 by mykman            #+#    #+#             */
/*   Updated: 2021/12/15 12:47:13 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.checker_mode = 0;
	if (set_data(argc, argv, &data))
		ft_error(data);
	if (issorted(data.a.lst, data.a.len - 1, -1))
		ft_exit(data, EXIT_SUCCESS);
	push(&data, &data.a, &data.b);
	push(&data, &data.a, &data.b);
	rotate(&data, &data.a);
	ft_printf("Fin du programme!\n");
	ft_lstiter(data.operations, &print_operation);
	ft_exit(data, EXIT_SUCCESS);
}
