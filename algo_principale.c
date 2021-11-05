/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_principale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:29:13 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/05 18:35:04 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo(t_stack *Stack_a)
{
	t_stack *Stack_b;

	Stack_b = NULL;
	if (ft_size_stack(&Stack_a) == 1)
		return ;
	if (ft_size_stack(&Stack_a) == 2)
	{
		ft_algo_2(Stack_a);
		ft_display_stack(Stack_a);
		printf("Done algo _2\n");
	}
	if (ft_size_stack(&Stack_a) == 3)
	{
		ft_algo_3(Stack_a);
		ft_display_stack(Stack_a);
		printf("Done algo _3\n");
	}
	if (ft_size_stack(&Stack_a) == 4)
		ft_algo_4(Stack_a);
	if (ft_size_stack(&Stack_a) == 5)
		ft_algo_5(Stack_a, Stack_b);
	else if (ft_size_stack(&Stack_a) > 5)
		ft_algo_big(Stack_a, Stack_b);
}



void	ft_algo_2(t_stack *Stack_a)
{
	t_stack		*tmp;

	tmp = Stack_a;
	if (tmp->number > tmp->next->number)
		ft_swap(Stack_a, 'a');
	ft_display_stack(Stack_a);
}


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

void	ft_algo_4(t_stack *Stack_a)
{
	Stack_a = NULL;
	printf("ft_algo_4 is in construction hihi\n");
}


void	ft_algo_5(t_stack *Stack_a, t_stack *Stack_b)
{
	Stack_a = NULL;
	Stack_b = NULL;
	printf("ft_algo_5 is in construction hihi\n");
}




void	ft_algo_big(t_stack *Stack_a, t_stack *Stack_b)
{
	Stack_a = NULL;
	Stack_b = NULL;
	printf("ft_algo_big is in construction\nPlease come back later\n");
}
