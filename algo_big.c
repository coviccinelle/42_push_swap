/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:33:07 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/11 12:33:31 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void	ft_algo_big(t_stack **stack_a, t_stack **stack_b)
// {
// 	*stack_a = NULL;
// 	*stack_b = NULL;
// 	// ft_diff(stack_a); // find "ecart" -> the diff
// 	// ft_find_pivot(stack_a); //Find the biggest ecart to be the reference
// 	// ft_not_sorted(stack_a); // Find numbers to push in stack_b
// 	// ft_index(stack_a); // define index for elements -> reference = 0, under len/2 = -index
// 	// ft_adap_index(stack_a); // change index, for under len/2, after reference = - index...
// 	// ft_push_in_b(stack_a, stack_b); // push not_sorted in stack_b
// 	// ft_reset_index(stack_a); // reset index in stack_a
// 	printf("ft_algo_big is in construction\nPlease come back later\n");
// }


	// ft_diff(stack_a); // find "ecart" -> the diff

// int ft_diff(t_stack **stack_a, )
// {
    
// }



    // ft_find_pivot(stack_a); //Find the biggest ecart to be the reference
 	// ft_not_sorted(stack_a); // Find numbers to push in stack_b
 	// ft_index(stack_a); // define index for elements -> reference = 0, under len/2 = -index
	// ft_adap_index(stack_a); // change index, for under len/2, after reference = - index...
 	// ft_push_in_b(stack_a, stack_b); // push not_sorted in stack_b
	// ft_reset_index(stack_a); // reset index in stack_a

int		ft_sorted(t_stack **stack_a)
{
	t_stack		*tmp;

	tmp = (*stack_a);
	while (tmp->next->next)
	{
		while (tmp->next->next && (tmp->number < tmp->next->number))
			tmp = tmp->next;
		if (tmp->number > tmp->next->number)
			return (0);
	}
	return (1);
}

void		ft_index(t_stack *stack_a)
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

// int		loop_stack(t_stack *stack, t_stack *start)
// {
// 	t_stack		*tmp;
// 	int 		i;
// 	int			max_i;

// 	i = 0;
// 	max_i = -1;
// 	tmp = start;
// 	while (tmp)
// 	{
// 		if (tmp->index > max_i)
// 		{
// 			max_i = tmp->index;
// 			i++;
// 		}
// 		tmp = tmp->next;
// 		if (tmp == NULL)
// 			tmp = stack;
// 		if (tmp = stack)
// 			break ;
// 	}
// 	return (i);
// }


// int		get_max_sorted(t_stack *first)
// {

// }


t_stack		*ft_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;
	// int		max_num;

	
	tmp = (stack);
	// max_num = tmp->number;
	while (tmp->next)
	{
		if (tmp->number > max->number)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*ft_min(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = stack;
	while (tmp->next)
	{
		printf("min->number = %d\n", min->number);
		if (tmp->number < min->number)
		{
			printf("min->number = %d\n", min->number);
			min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}

int		ft_min_steps(t_stack *stack, int index)
{
	int			step;

	step = 0;
	if (index <= (ft_size_stack(&stack) / 2))
		step = index;
	else if (index > (ft_size_stack(&stack) / 2))
		step = ft_size_stack(&stack) - index;
	return (step);
}

// int		get_i_max(t_stack *stack, int max)
// {
// 	t_stack *tmp;
// 	int		i;

// 	i = 0;
// 	tmp = stack;
// 	while (tmp)
// 	{
// 		if (tmp->number == max)
// 			return (i);
// 		else
// 		{
// 			stack->index = i;
// 			stack = stack->next;
// 			i++;
// 		}
// 		// stack = stack->next;
// 	}
// 	return (i);
// }

int	ft_absolute(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}