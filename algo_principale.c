/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_principale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:29:13 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/27 16:23:49 by thi-phng         ###   ########.fr       */
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
