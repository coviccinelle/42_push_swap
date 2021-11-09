/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_principale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:29:13 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/06 18:33:11 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_size_stack(stack_a) == 1)
		return ;
	if (ft_size_stack(stack_a) == 2)
	{
		ft_algo_2(stack_a);
	//	ft_display_stack(Stack_a);
		printf("Done algo _2\n");
	}
	if (ft_size_stack(stack_a) == 3)
	{
		ft_algo_3(stack_a);
	//	ft_display_stack(Stack_a);
		printf("Done algo _3\n");
	}
	if (ft_size_stack(stack_a) == 4)
		ft_algo_4(stack_a);
	if (ft_size_stack(stack_a) == 5)
		ft_algo_5(stack_a, stack_b);
	else if (ft_size_stack(stack_a) > 5)
		ft_algo_big(stack_a, stack_b);
}



void	ft_algo_2(t_stack **stack_a)
{
	t_stack		*tmp;

	tmp = (*stack_a);
	if (tmp->number > tmp->next->number)
		ft_swap(stack_a, 'a');
	ft_display_stack(*stack_a);
}


void	ft_algo_3(t_stack	**stack)
{
	int		st;
	int		nd;
	int		rd;

	st = (*stack)->number;
	nd = (*stack)->next->number;
	rd = (*stack)->next->next->number;
	printf("Im over here inside algo_3\n");
	// 3 2 5
	if (st > nd && nd < rd && rd > st)
		ft_swap(stack, 'a');
	// 5 3 2
	else if (st > nd && nd > rd && rd < st)
	{
		ft_swap(stack, 'a');//-> 3 5 2
		ft_reverse_rotate(stack, 'a');
	}
	// 5 2 3
	else if (st > nd && nd < rd && rd < st)
		ft_rotate(stack, 'a');
	// 2 5 3
	else if (st < nd && nd > rd && rd > st)
	{
		ft_swap(stack, 'a');
		ft_rotate(stack, 'a');
	}
	// 3 5 2
	else if (st < nd && nd > rd && rd < st)
		ft_reverse_rotate(stack, 'a');
}

void	ft_algo_4(t_stack **stack_a)
{
	(*stack_a) = NULL;
	printf("ft_algo_4 is in construction hihi\n");
}


void	ft_algo_5(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
	printf("ft_algo_5 is in construction hihi\n");
}




void	ft_algo_big(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
	printf("ft_algo_big is in construction\nPlease come back later\n");
}
