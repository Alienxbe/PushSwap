/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:11:22 by mykman            #+#    #+#             */
/*   Updated: 2021/11/12 02:04:56 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_data data, int exit_value)
{
	if (data.operations)
		ft_lstclear(&data.operations, NULL);
	ft_lstclear(&data.to_clear, &free);
	exit(exit_value);
}

void	ft_error(t_data data)
{
	ft_putendl_fd("Error", 2);
	ft_exit(data, EXIT_FAILURE);
}
