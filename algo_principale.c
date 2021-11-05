/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_principale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:29:13 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/05 15:43:50 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo(t_stack *Stack_a, t_stack *Stack_b)
{
	if (ft_size_stack(&Stack_a) == 1)
		return ;
	if (ft_size_stack(&Stack_a) == 2)
		ft_algo_2(Stack_a);
	if (ft_size_stack(&Stack_a) == 3)
		ft_algo_3(Stack_a);
	if (ft_size_stack(&Stack_a) == 5)
		ft_algo_5(Stack_a);
	else if (ft_size_stack(&Stack_a) > 5)
		ft_algo_big(Stack_a, Stack_b);
}


void	ft_algo_5(t_stack *Stack)
{
	Stack = NULL;
	printf("ft_algo_5 is in construction hihi\n");
}




void	ft_algo_big(t_stack *Stack_a, t_stack *Stack_b)
{
	Stack_a = NULL;
	Stack_b = NULL;
	printf("ft_algo_big is in construction\nPlease come back later\n");
}
