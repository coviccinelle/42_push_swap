/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:32:01 by thi-phng          #+#    #+#             */
/*   Updated: 2021/12/02 17:17:33 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_free(t_stack **st)
{
	t_stack	*tmp;

	while ((*st))
	{
		tmp = (*st);
		(*st) = (*st)->next;
		free(tmp);
	}
}

void	ft_free_1st(t_stack **st, int n)
{
	if (n == 1)
	{
		printf("Error\n");
		simple_free(st);
	}
	else
		simple_free(st);
}

void	ft_free(t_stack **st_a, t_stack **st_b, int n)
{
	if (n == 1)
	{
		printf("Error\n");
		if ((*st_a))
			simple_free(st_a);
		if ((*st_b))
			simple_free(st_b);
	}
	else
	{
		if ((*st_a))
			simple_free(st_a);
		if ((*st_b))
			simple_free(st_b);
	}
}
