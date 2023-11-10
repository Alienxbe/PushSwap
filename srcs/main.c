/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:48:24 by mykman            #+#    #+#             */
/*   Updated: 2023/11/10 23:06:22 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "solve.h"
#include "utils.h"

int	free_return(int value, t_dlist *stack, int *content)
{
	if (content)
		free(content);
	if (stack)
		ft_dlstclear(&stack, NULL);
	return (value);
}

void	print_moves(void *content)
{
	char *str;

	str = content;
	ft_printf("%s -> ", str);
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	t_dlist	*moves;
	int		*content;

	if (argc < 2)
		return (1);
	content = NULL;
	moves = NULL;
	stack_a = fill_stack(argc, argv, &content);
	stack_b = NULL;
	if (!stack_a || is_sorted(stack_a))
		return (free_return(1, stack_a, content));

	print_stack(stack_a, stack_b);
	moves = cost_sort(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);

	ft_dlstiter(moves, &print_moves);
	ft_printf("\nOp count : %d\n", ft_dlstsize(moves, moves->next));

	// Free
	ft_dlstclear(&stack_a, NULL);
	ft_dlstclear(&stack_b, NULL);
	ft_dlstclear(&moves, NULL);
	free(content);
	return (0);
}
