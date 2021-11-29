/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:32:01 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/29 14:48:01 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_free_1st(t_stack **st, int n)
{
	t_stack	*tmp;

    if (n == 1)
        printf("Error\nFREE 1stack\n");
	while ((*st))
	{
		tmp = (*st);
		(*st_a) = (*st)->next;
		free(tmp);
	}
}


void	ft_free(t_stack **st_a, t_stack **st_b, int n)
{
	t_stack	*tmp;

    if (n == 1)
        printf("Error\nFREE 2 stacks\n");
	while ((*st_a))
	{
		tmp = (*st_a);
		(*st_a) = (*st_a)->next;
		free (tmp);
	}
	while ((*st_b))
	{
		tmp = (*st_b);
		(*st_b) = (*st_b)->next;
		free (tmp);
	}
}

// void    ft_error(t_stack **st_a, t_stack **st_b, int n)
// {
//     if (n == 1)
//     {
//         printf("Error\n");
//         ft_free(st_a, st_b);
//     }
//     else if (n == 0)
//         ft_free(st_a, st_a);
//     else if (n == 2)
//     {
//         printf("Error\n");
//         ft_free(st_a);
//     }
//     else if (n == 3)
//     {
//         ft_free(st_a);
//     }
// }
