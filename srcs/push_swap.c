/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:48:24 by mykman            #+#    #+#             */
/*   Updated: 2021/10/27 11:07:18 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_element(void *content)
{
	ft_printf("%s\n", (char *)content);
}

int main(int argc, char **argv)
{
    int     i;
    t_dlist *stack_a;
    t_dlist *stack_b;
    t_dlist *new;
    
    if (argc < 2)
        return (1);
    stack_b = NULL;
    i = 0;
    while (++i < argc)
    {
        new = ft_dlstnew(argv[i]);
        ft_dlstadd_back(&stack_a, new);
        if (!new)
            return (1);
    }
    ft_dlstiter(stack_a, &print_element);
    ft_dlstclear(&stack_a, NULL);
    return (0);
}
