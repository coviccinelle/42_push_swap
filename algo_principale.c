/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_principale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:29:13 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/06 18:33:11 by thi-phng         ###   ########.fr       */
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

int		ft_sorted(t_stack **stack_a)
{
	t_stack		*tmp;

	tmp = (*stack_a);
	while (tmp->next->next)
	{
		while (tmp->next->next && (tmp->number < tmp->next->number))
		{
			tmp = tmp->next;
		}
		if (tmp->number > tmp->next->number)
			return (0);
	}
	return (1);
}

void	ft_algo_2(t_stack **stack_a)
{
	t_stack		*tmp;

	tmp = (*stack_a);
	if (tmp->number > tmp->next->number)
		ft_swap(stack_a, 'a');
}


void	ft_algo_3(t_stack	**stack)
{
	int		st;
	int		nd;
	int		rd;

	st = (*stack)->number;
	nd = (*stack)->next->number;
	rd = (*stack)->next->next->number;
	if (ft_sorted(stack) == 1)
		printf("Sorted hihi 11 11 \n");
	else
	{
	// 3 2 5
		if (st > nd && nd < rd && rd > st)
			ft_swap(stack, 'a');
	// 5 3 2
		else if (st > nd && nd > rd && rd < st)
		{
			ft_swap(stack, 'a');//-> 3 5 2
			ft_reverse_rotate(stack, 'a');
		}
	// 5 2 3
		else if (st > nd && nd < rd && rd < st)
			ft_rotate(stack, 'a');
	// 2 5 3
		else if (st < nd && nd > rd && rd > st)
		{
			ft_swap(stack, 'a');
			ft_rotate(stack, 'a');
		}
	// 3 5 2
		else if (st < nd && nd > rd && rd < st)
			ft_reverse_rotate(stack, 'a');
	}
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

//TODO: ft_right_place(t_stack** stack_a, t_stack **stack_b) //compare 2 pointers in stack_a
// 						to find a place to stuck first element of stack_b in   
//				=> return an int = number of operations needed to get there
void	ft_algo_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp_a;

	
	if (ft_sorted(stack_a) == 1)
		printf("Sorted hihi \n");
	else
	{
		ft_push(stack_a, stack_b, 'b');
		ft_algo_3(stack_a);
		tmp_a = (*stack_a);
		if (tmp_a->number < (*stack_b)->number && (*stack_b)->number < tmp_a->next->number)
		{
			ft_rotate(stack_a, 'a');
			ft_push(stack_b, stack_a, 'a');
			ft_reverse_rotate(stack_a, 'a');
		}

	// if (ft_sorted(stack_a) == 1)
	// 	printf("stack_a sorted hihi \n");
	}
	printf("----- \n");
	ft_display_2_stacks(*stack_a, *stack_b);
	printf("ft_algo_4 is in construction hihi\n");
}



void	ft_algo_5(t_stack **stack_a, t_stack **stack_b)
{
	int		st_b;
	int		st_a;
	int		st_aa;

	if (ft_sorted(stack_a) == 1)
		printf("Sorted hihi \n");
	else
	{
		ft_push(stack_a, stack_b, 'b');
		ft_push(stack_a, stack_b, 'b');//push 2 first in b
		ft_algo_3(stack_a); // sort in a
		st_b = (*stack_b)->number;
		st_a = (*stack_a)->number;
		st_aa = (*stack_a)->next->number;
	}
	printf("------ final algo _5 -----\n");
	ft_display_2_stacks(*stack_a, *stack_b);
	printf("ft_algo_5 is in construction hihi\n");
}

void	ft_algo_big(t_stack **stack_a, t_stack **stack_b)
{
	// *stack_a = NULL;
	*stack_b = NULL;

	if (ft_sorted(stack_a) == 1)
		printf("Sorted hihi 11 11 \n");
	else
	{
	// ft_diff(stack_a); // find "ecart" -> the diff
	// ft_find_pivot(stack_a); //Find the biggest ecart to be the reference
	// ft_not_sorted(stack_a); // Find numbers to push in stack_b
	// ft_index(stack_a); // define index for elements -> reference = 0, under len/2 = -index
	// ft_adap_index(stack_a); // change index, for under len/2, after reference = - index...
	// ft_push_in_b(stack_a, stack_b); // push not_sorted in stack_b
	// ft_reset_index(stack_a); // reset index in stack_a
	}
	printf("ft_algo_big is in construction\nPlease come back later\n");
}
