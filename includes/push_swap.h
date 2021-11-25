/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:06:45 by mykman            #+#    #+#             */
/*   Updated: 2021/11/18 20:26:31 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/includes/libft.h"

typedef struct s_stack
{
	int				*lst;
	int				len;
	unsigned char	id;
}	t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_list	*operations;
	t_list	*to_clear;
	int		op_list[11];
}	t_data;

enum	e_operations
{
	op_sa,
	op_sb,
	op_ss,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr
};

/*
** MAIN FUNCTIONS
*/

void	swap(t_data *data, t_stack *stack);
void	push(t_data *data, t_stack *from, t_stack *to);

void	add_operation(t_data *data, int op_id);

/*
** UTILS
*/

int		set_data(int argc, char **argv, t_data *data);
int		issorted(int *lst, int start, int end);

void	ft_exit(t_data data, int exit_value);

#endif