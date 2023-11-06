/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:35:50 by mykman            #+#    #+#             */
/*   Updated: 2023/11/07 00:17:29 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

int	is_sorted(t_dlist *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	crap_sort(t_dlist **stack_a, t_dlist **stack_b)
{
	while (*stack_a)
	{
		rotate_top(stack_a, ft_dlstmin(*stack_a));
		if (is_sorted(*stack_a))
			break ;
		ft_px(stack_a, stack_b, "pb");
	}
	while (*stack_b)
	{
		ft_px(stack_b, stack_a, "pa");
	}
}

static t_dlist	*get_after(t_dlist **stack, int min_value)
{
	t_dlist	*current;
	t_dlist	*min;

	min = NULL;
	current = *stack;
	while (current)
	{
		if ((!min || *(int *)current->content > *(int *)min->content)
			&& *(int *)current->content < min_value)
			min = current;
		current = current->next;
	}
	return (min);
}

void	cost_sort(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*min_cost_element;
	size_t	min_cost;
	size_t	tmp_cost;
	t_dlist *after;

	while (*stack_a)
	{
		min_cost_element = NULL;
		min_cost = 0;
		for (t_dlist *tmp = *stack_a; tmp != NULL; tmp = tmp->next)
		{
			tmp_cost = get_cost(stack_a, stack_b, tmp);
			ft_printf("Cost (%d) -> %d\n", *(int *)tmp->content, tmp_cost);
			if (!min_cost_element || tmp_cost < min_cost)
			{
				min_cost_element = tmp;
				min_cost = tmp_cost;
			}
		}
		rotate_top(stack_a, min_cost_element);

		after = get_after(stack_b, min_cost);
		if (!after)
			after = ft_dlstmin(*stack_b);
		if (after)
			ft_printf("After: %d\n", *(int *)after->content);
		rotate_top(stack_b, after);
		ft_px(stack_a, stack_b, "pb");
		ft_printf("min: %d\n", min_cost);
		print_stack(*stack_a, *stack_b);
	}
}
