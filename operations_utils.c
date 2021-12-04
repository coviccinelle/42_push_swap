/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:24:17 by thi-phng          #+#    #+#             */
/*   Updated: 2021/12/04 10:17:34 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// DOUBLONS PART //
int	ft_doublons(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = stack;
	if (!stack || !tmp1 || !tmp1->next)
		return (0);
	tmp2 = tmp1->next;
	while (tmp1)
	{
		while (tmp2)
		{
			if (tmp1->number == tmp2->number)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		if (tmp1->next == NULL)
			break ;
		tmp2 = tmp1->next;
	}
	return (0);
}

int	ft_size_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_init(t_env *f)
{
	f->stack_a = NULL;
	f->stack_b = NULL;
}

void	ft_index(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->index = i;
		stack_a = stack_a->next;
		i++;
	}
}
