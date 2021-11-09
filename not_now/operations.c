/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:00:38 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/28 16:35:59 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_1(t_stack **stack, char c)
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
