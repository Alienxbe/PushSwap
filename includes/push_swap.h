/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:06:45 by mykman            #+#    #+#             */
/*   Updated: 2021/11/02 09:38:15 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/includes/libft.h"

void	ft_sx(t_dlist **stack);
void	ft_ss(t_dlist **stack_a, t_dlist **stack_b);
void	ft_px(t_dlist **stack_from, t_dlist **stack_to);
void	ft_rx(t_dlist **stack);
void	ft_rr(t_dlist **stack_a, t_dlist **stack_b);
void	ft_rrx(t_dlist **stack);
void	ft_rrr(t_dlist **stack_a, t_dlist **stack_b);

#endif