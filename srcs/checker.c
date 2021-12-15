/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:35:17 by mykman            #+#    #+#             */
/*   Updated: 2021/12/15 13:00:32 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_op(t_data *data, char *line)
{
	static char	*op_text[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	i = -1;
	while (++i < 11)
	{
		if (!ft_strncmp(line, op_text[i], ft_strlen(line)))
		{
			add_operation(data, i);
			return ;
		}
	}
	ft_error(*data);
}

void	do_op(t_data *data)
{
	t_list	*ptr;
	static void	(*f[11])(t_data *data) = {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

	ptr = data->operations;
	while (ptr)
	{
		f[*(int *)ptr->content](data);
		print_stack(*data, 10);
		ptr = ptr->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*line;
	int		ret;

	data.checker_mode = 1;
	if (set_data(argc, argv, &data))
		ft_error(data);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		parse_op(&data, line);
		free(line);
	}
	if (line)
		free(line);
	ft_printf("----------------------\n");
	do_op(&data);
	ft_exit(data, EXIT_SUCCESS);
}
