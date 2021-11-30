/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:09:01 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/29 16:53:54 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_new_element(t_stack	**stack, int n)
{
	t_stack	*tmp;
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		ft_free_1st(stack, 0);
		return ;
	}
	if ((*stack) == NULL)
	{
		(*stack) = new;
		new->next = NULL;
		new->number = n;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		new->number = n;
	}
}

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_size_stack(stack) >= 2)
	{
		tmp1 = *stack;
		tmp2 = (*stack)->next->next;
		*stack = (*stack)->next;
		(*stack)->next = tmp1;
		tmp1->next = tmp2;
	}
	printf("s%c\n", c);
}

int	ft_rotate(t_stack **stack, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp_curs;

	if (!(*stack))
		return (0);
	else
	{
		tmp1 = *stack;
		tmp_curs = *stack;
		*stack = (*stack)->next;
		while (tmp_curs->next)
			tmp_curs = tmp_curs->next;
		tmp_curs->next = tmp1;
		tmp1->next = NULL;
	}
	printf("r%c\n", c);
	return (1);
}

int	ft_reverse_rotate(t_stack **stack, char c)
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
	printf("rr%c\n", c);
	return (1);
}

//St_t = stack take;
//St_r = stack receive;
int	ft_push(t_stack **st_t, t_stack **st_r, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!(*st_t))
		return (0);
	else
	{
		tmp1 = *st_t;
		tmp2 = *st_r;
		*st_t = (*st_t)->next;
		*st_r = tmp1;
		tmp1->next = tmp2;
	}
	printf("p%c\n", c);
	return (0);
}
