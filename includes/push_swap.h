/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:06:45 by mykman            #+#    #+#             */
/*   Updated: 2021/12/15 12:54:32 by mykman           ###   ########.fr       */
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
	int		checker_mode;
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
void	rotate(t_data *data, t_stack *stack);
void	rrotate(t_data *data, t_stack *stack);
void	add_operation(t_data *data, int op_id);

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);



/*
** CHECKER FUNCTIONS
*/

void	parse_op(t_data *data, char *line);


/*
** UTILS
*/

int		set_data(int argc, char **argv, t_data *data);
int		issorted(int *lst, int start, int end);

// Print functions
void	print_operation(void *content);
void	print_stack(t_data data, int argc);

// Exit functions
void	ft_exit(t_data data, int exit_value);
void	ft_error(t_data data);

#endif