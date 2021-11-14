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


void	ft_algo_2(t_stack **stack_a)
{
	t_stack		*tmp;

	tmp = (*stack_a);
	if (tmp->number > tmp->next->number)
		ft_swap(stack_a, 'a');
}


void	ft_algo_3(t_stack	**st)
{
	int		nd;
	int		rd;

	nd = (*st)->next->number;
	rd = (*st)->next->next->number;
	if (!ft_sorted(st))
	{
	// 3 2 5
		if ((*st)->number > nd && nd < rd && rd > (*st)->number)
			ft_swap(st, 'a');
	// 5 3 2
		else if ((*st)->number > nd && nd > rd && rd < (*st)->number)
		{
			ft_swap(st, 'a');//-> 3 5 2
			ft_reverse_rotate(st, 'a');
		}
	// 5 2 3
		else if ((*st)->number > nd && nd < rd && rd < (*st)->number)
			ft_rotate(st, 'a');
	// 2 5 3
		else if ((*st)->number < nd && nd > rd && rd > (*st)->number)
		{
			ft_swap(st, 'a');
			ft_rotate(st, 'a');
		}
	// 3 5 2
		else if ((*st)->number < nd && nd > rd && rd < (*st)->number)
			ft_reverse_rotate(st, 'a');
	}
}


//TODO: ft_right_place(t_stack** stack_a, t_stack **stack_b) //compare 2 pointers in stack_a
// 						to find a place to stuck first element of stack_b in   
//				=> return an int = number of operations needed to get there


void	ft_algo_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*min;
	int 		min_steps;

	if (!ft_sorted(stack_a))
	{
		min = ft_min(*stack_a);
		ft_index(*stack_a);
		min_steps = ft_min_steps(*stack_a, min->index);
		get_num_on_top(stack_a, min->index, min_steps);
		ft_push(stack_a, stack_b, 'b');
		ft_algo_3(stack_a);
		ft_push(stack_b, stack_a, 'b');
	}
	printf("----- \n");
	ft_display_stack(*stack_a);
	printf("---stack_b-- \n");
	ft_display_stack(*stack_b);
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
	// ft_display_stack(*stack_a);
	printf("done get_num_on_top\n");
	return (0);
}


void	ft_algo_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*min;
	t_stack		*min_2;
	t_stack		*tmp;
	int 		min_steps;

	if (!ft_sorted(stack_a))
	{
		min = ft_min(*stack_a);
		ft_index(*stack_a);
		min_steps = ft_min_steps(*stack_a, min->index);
		get_num_on_top(stack_a, min->index, min_steps);
		ft_push(stack_a, stack_b, 'b');
		min_2 = ft_min(*stack_a);
		ft_index(*stack_a);
		tmp = (*stack_a);
		min_steps = ft_min_steps(*stack_a, min_2->index);
		get_num_on_top(stack_a, min_2->index, min_steps);
		ft_push(stack_a, stack_b, 'b');
		ft_algo_3(stack_a);
		ft_push(stack_b, stack_a, 'a');
		ft_push(stack_b, stack_a, 'a');
	}
	printf("------ final algo _5 -----\n");
	ft_display_stack(*stack_a);
}

void	ft_algo_big(t_stack **stack_a, t_stack **stack_b)
{
	// *stack_a = NULL;
	*stack_b = NULL;
	t_stack *max;
	t_stack *min;
	t_stack *last;

	max = ft_max(*stack_a);
	last = get_last(*stack_a);
	printf("last_element in stack_a is %d\n", last->number);
	printf("maxx_element in stack_a is %d\n", max->number);
	ft_display_stack(*stack_a);
	min = ft_min(*stack_a);
	printf("minn_element in stack_a is %d\n", min->number);
	printf("maxx_element in stack_a is %d\n", max->number);


	// if (ft_sorted(stack_a) == 1)
	// 	printf("Sorted hihi 11 11 \n");
	// else
	// {
	// // ft_diff(stack_a); // find "ecart" -> the diff
	// // ft_find_pivot(stack_a); //Find the biggest ecart to be the reference
	// // ft_not_sorted(stack_a); // Find numbers to push in stack_b
	// // ft_index(stack_a); // define index for elements -> reference = 0, under len/2 = -index
	// // ft_adap_index(stack_a); // change index, for under len/2, after reference = - index...
	// // ft_push_in_b(stack_a, stack_b); // push not_sorted in stack_b
	// // ft_reset_index(stack_a); // reset index in stack_a
	// }
	printf("ft_algo_big is in construction\nPlease come back later\n");
}
