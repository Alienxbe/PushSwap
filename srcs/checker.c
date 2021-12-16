/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:35:17 by mykman            #+#    #+#             */
/*   Updated: 2021/12/16 15:13:40 by mykman           ###   ########.fr       */
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
		if (!ft_strncmp(line, op_text[i], ft_strlen(op_text[i]))
			&& !ft_strncmp(line, op_text[i], ft_strlen(line)))
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
	do_op(&data);
	if (issorted(data.a.lst, data.a.len, -1) && !data.b.len)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_exit(data, EXIT_SUCCESS);
}
