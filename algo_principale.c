/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_principale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:29:13 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/27 17:06:52 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	ft_algo(t_stack **stack_a, t_stack **stack_b)
{
	ft_display_stack(*stack_a);
	if (ft_size_stack(stack_a) == 1)
		return ;
	if (ft_size_stack(stack_a) == 2)
	{
		ft_algo_2(stack_a);
		printf("Done algo _2\n");
	}
	if (ft_size_stack(stack_a) == 3)
	{
		ft_algo_3(stack_a);
		printf("Done algo _3\n");
	}
	if (ft_size_stack(stack_a) == 4)
		ft_algo_4(stack_a, stack_b);
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
}

void	ft_algo_3(t_stack **st)
{
	int		nd;
	int		rd;

	nd = (*st)->next->number;
	rd = (*st)->next->next->number;
	if (!ft_sorted(st))
	{
		if ((*st)->number > nd && nd < rd && rd > (*st)->number)
			ft_swap(st, 'a');
		else if ((*st)->number > nd && nd > rd && rd < (*st)->number)
		{
			ft_swap(st, 'a');
			ft_reverse_rotate(st, 'a');
		}
		else if ((*st)->number > nd && nd < rd && rd < (*st)->number)
			ft_rotate(st, 'a');
		else if ((*st)->number < nd && nd > rd && rd > (*st)->number)
		{
			ft_swap(st, 'a');
			ft_rotate(st, 'a');
		}
		else if ((*st)->number < nd && nd > rd && rd < (*st)->number)
			ft_reverse_rotate(st, 'a');
	}
}

void	ft_algo_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*min;
	int 		min_steps;

	if (!ft_sorted(stack_a))
	{
		min = ft_min(*stack_a);
		ft_index(*stack_a);
		min_steps = ft_min_steps(*stack_a, min->index);
		get_num_on_top(stack_a, min->index, min_steps);
		ft_push(stack_a, stack_b, 'b');
		ft_algo_3(stack_a);
		ft_push(stack_b, stack_a, 'b');
	}
	printf("----- \n");
	ft_display_stack(*stack_a);
	printf("---stack_b-- \n");
	ft_display_stack(*stack_b);
}

void	ft_algo_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*min;
	t_stack		*min_2;
	t_stack		*tmp;
	int 		min_steps;

	if (!ft_sorted(stack_a))
	{
		min = ft_min(*stack_a);
		ft_index(*stack_a);
		min_steps = ft_min_steps(*stack_a, min->index);
		get_num_on_top(stack_a, min->index, min_steps);
		ft_push(stack_a, stack_b, 'b');
		min_2 = ft_min(*stack_a);
		ft_index(*stack_a);
		tmp = (*stack_a);
		min_steps = ft_min_steps(*stack_a, min_2->index);
		get_num_on_top(stack_a, min_2->index, min_steps);
		ft_push(stack_a, stack_b, 'b');
		ft_algo_3(stack_a);
		ft_push(stack_b, stack_a, 'a');
		ft_push(stack_b, stack_a, 'a');
	}
	printf("------ final algo _5 -----\n");
	ft_display_stack(*stack_a);
}
