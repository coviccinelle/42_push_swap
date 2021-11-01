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

void	ft_swap_1(t_stack **Stack, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_size_stack(Stack) >= 2)
	{
		tmp1 = *Stack;
		tmp2 = (*Stack)->next->next;
		*Stack = (*Stack)->next;
		(*Stack)->next = tmp1;
		tmp1->next = tmp2;
	}
	printf("s%c\n", c);
}
