/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:08:33 by mykman            #+#    #+#             */
/*   Updated: 2021/12/03 15:33:35 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	new_stack(t_stack *stack, int len, unsigned char id)
{
	if (!stack)
		return (1);
	stack->len = len;
	stack->id = id;
	stack->lst = (int *)ft_calloc(stack->len, sizeof(int));
	if (!stack->lst)
		return (1);
	return (0);
}

int	set_data(int argc, char **argv, t_data *data)
{
	t_stack	a;
	t_stack	b;
	int		ret;
	int		i;

	ret = new_stack(&a, argc - 1, 0) + new_stack(&b, argc - 1, 1);
	data->a = a;
	data->b = b;
	data->b.len = 0;
	data->to_clear = NULL;
	data->operations = NULL;
	ft_lstadd_back(&data->to_clear, ft_lstnew(data->a.lst));
	ft_lstadd_back(&data->to_clear, ft_lstnew(data->b.lst));
	i = -1;
	while (++i < 11)
		data->op_list[i] = i;
	i = 0;
	while (!ret && ++i < argc)
	{
		if (!ft_isnumber(argv[argc - i]))
			return (1);
		data->a.lst[i - 1] = ft_atoi(argv[argc - i]);
	}
	return (ret);
}
