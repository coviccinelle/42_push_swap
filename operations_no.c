/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_no.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:20:13 by thi-phng          #+#    #+#             */
/*   Updated: 2021/12/04 10:17:28 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_stack(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->number);
		tmp = tmp->next;
	}
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_size_stack(stack_a) >= 2)
	{
		tmp1 = *stack_a;
		tmp2 = (*stack_a)->next->next;
		*stack_a = (*stack_a)->next;
		(*stack_a)->next = tmp1;
		tmp1->next = tmp2;
	}
	if (ft_size_stack(stack_b) >= 2)
	{
		tmp1 = *stack_b;
		tmp2 = (*stack_b)->next->next;
		*stack_b = (*stack_b)->next;
		(*stack_b)->next = tmp1;
		tmp1->next = tmp2;
	}
	printf("ss\n");
}

int	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp1;
	t_stack	*tmp_curs;

	if (*stack_a)
	{
		tmp1 = *stack_a;
		tmp_curs = *stack_a;
		*stack_a = (*stack_a)->next;
		while (tmp_curs->next)
			tmp_curs = tmp_curs->next;
		tmp_curs->next = tmp1;
		tmp1->next = NULL;
	}
	if (*stack_b)
	{
		tmp1 = *stack_b;
		tmp_curs = *stack_b;
		*stack_b = (*stack_b)->next;
		while (tmp_curs->next)
			tmp_curs = tmp_curs->next;
		tmp_curs->next = tmp1;
		tmp1->next = NULL;
	}
	printf("rr\n");
	return (1);
}

int	ft_rr_ro(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp_run;

	if (!(*stack))
		return (0);
	else
	{
		tmp1 = *stack;
		while ((*stack)->next)
		{
			tmp_run = *stack;
			*stack = (*stack)->next;
		}
		tmp_run->next = NULL;
		(*stack)->next = tmp1;
	}
	return (1);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
		ft_rr_ro(stack_a);
	if (stack_b)
		ft_rr_ro(stack_b);
	printf("rrr\n");
}
