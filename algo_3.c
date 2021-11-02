/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:37:34 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/01 17:08:47 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_3(t_stack	*Stack)
{
	int		st;
	int		nd;
	int		rd;

	st = Stack->number;
	nd = Stack->next->number;
	rd = Stack->next->next->number;
	// 3 2 5
	if (st > nd && nd < rd && rd > st)
		ft_swap(Stack, 'a');
	// 5 3 2
	else if (st > nd && nd > rd && rd < st)
	{
		ft_swap(Stack, 'a');//-> 3 5 2
		ft_reverse_rotate(Stack, 'a');
	}
	// 5 2 3
	else if (st > nd && nd < rd && rd < st)
		ft_rotate(Stack, 'a');
	// 2 5 3
	else if (st < nd && nd > rd && rd > st)
	{
		ft_swap(Stack, 'a');
		ft_rotate(Stack, 'a');
	}
	// 3 5 2
	else if (st < nd && nd > rd && rd < st)
		ft_reverse_rotate(Stack, 'a');
}
