/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:03:24 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/27 17:14:31 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// minimum steps to move number to top of stack
int	ft_min_steps(t_stack *stack, int index)
{
	int			step;

	step = 0;
	if (index <= (ft_size_stack(&stack) / 2))
		step = index;
	else if (index > (ft_size_stack(&stack) / 2))
		step = ft_size_stack(&stack) - index;
	return (step);
}


int	get_num_on_top(t_stack **stack_a, int index, int min_steps)
{
	int i;

	i = min_steps;
	if (index > i)
	{
		printf(" ---- max or min->index = %d\n", index);
		while (i > 0)
		{
			ft_reverse_rotate(stack_a, 'a');
			i--;
		}
	}
	else if (index <= i)
	{
		while (i > 0)
		{
			ft_rotate(stack_a, 'a');
			i--;
		}
	}
	printf("done get_num_on_top\n");
	return (0);
}


void	get_stay(t_stack **st, t_stack *first)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		n;

	tmp = first;
	while (tmp == first)
	{
		tmp2 = tmp->next;
		n = tmp->number;
		if (!tmp2)
			tmp2 = (*st);
		while (tmp2->number != tmp->number)
		{
			if (n < tmp2->number)
			{
				tmp2->stay = 1;
				printf("Get_stay : tmp->number = %d, tmp2->number = %d, tmp->stay = %d\n\n", tmp->number, tmp2->number, tmp->stay);
				n = tmp2->number;
			}
			tmp2 = tmp2->next;
			if (!tmp2)
				tmp2 = (*st);
		}
		tmp = tmp->next;
	}
}

int	done_push_in_b(t_stack *st)
{
	t_stack	*tmp;

	tmp = st;
	while (tmp)
	{
		if (tmp->stay == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
