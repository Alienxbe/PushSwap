/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:54:04 by marykman          #+#    #+#             */
/*   Updated: 2024/08/30 23:41:27 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_dlist.h"

t_dlist	*fill_stack(int argc, char **argv, int **content);
int		is_sorted(t_dlist *stack);
int		ft_abs(int val);

#endif
