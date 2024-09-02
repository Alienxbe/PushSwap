/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:47:47 by marykman          #+#    #+#             */
/*   Updated: 2024/08/30 23:40:32 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "get_next_line.h"
#include "ft_dlist.h"
#include "utils.h"
#include "moves.h"

void	check_input(t_dlist **stack_a, t_dlist **stack_b)
{
	int		ret;
	char	*line;
	t_dlist	*moves;
	t_move	move;

	moves = NULL;
	move = MOVE_LEN;
	ret = 1;
	while (ret && move != MOVE_ERROR)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret)
		{
			move = ft_get_move_value(line);
			ft_move(&moves, stack_a, stack_b, move);
		}
		free(line);
	}
	if (move == MOVE_ERROR || *stack_b || !is_sorted(*stack_a))
		ft_fprintf(STDERR_FILENO, "Error\n");
	else
		ft_printf("OK\n");
	ft_dlstclear(&moves, NULL);
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	int		*content;

	if (argc < 2)
		return (1);
	content = NULL;
	stack_a = fill_stack(argc, argv, &content);
	stack_b = NULL;
	if (!stack_a)
	{
		if (content)
			free(content);
		return (1);
	}
	check_input(&stack_a, &stack_b);
	ft_dlstclear(&stack_a, NULL);
	ft_dlstclear(&stack_b, NULL);
	free(content);
	return (0);
}
