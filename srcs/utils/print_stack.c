/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:44:39 by marykman          #+#    #+#             */
/*   Updated: 2023/11/10 17:56:41 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_printf.h"

void	print_stack(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_printf("--------------------------------\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%5d\t|", *(int *)stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf("     \t|");
		if (stack_b)
		{
			ft_printf("\t%d", *(int *)stack_b->content);
			t_dlist	*first = ft_dlstmin(ft_dlstfirst(stack_b));
			int		offset = ft_dlstsize(first, first->previous);
			int		current_pos = ft_dlstsize(stack_b, stack_b->previous) - offset;
			current_pos = (current_pos < 0) ? ft_dlstsize(ft_dlstfirst(stack_b), ft_dlstfirst(stack_b)->next) - offset + 1 : current_pos;
			ft_printf("\t: [%d]\n", current_pos);
			stack_b = stack_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("%5s\t|\t%s\n", "-", "-");
	ft_printf("%5s\t|\t%s\n", "A", "B");
}