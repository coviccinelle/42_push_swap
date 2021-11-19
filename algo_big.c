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

    // ft_find_pivot(stack_a); //Find the biggest ecart to be the reference
 	// ft_not_sorted(stack_a); // Find numbers to push in stack_b
 	// ft_index(stack_a); // define index for elements -> reference = 0, under len/2 = -index
	// ft_adap_index(stack_a); // change index, for under len/2, after reference = - index...
 	// ft_push_in_b(stack_a, stack_b); // push not_sorted in stack_b
	// ft_reset_index(stack_a); // reset index in stack_a


// TODO: - create a big loop
// - Create another loop to find the list most sorted to stock
// - Swap if needed
// - Push the rest in stack_b
// - Caculate to find the place in a
// - Caculate to find the mi_steps needed to push back in place
// - Push back in a


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

// int		loop_stack(t_stack *st, t_stack *start, int tri)
// {
// 	t_stack		*loop;
// 	int 		max_count;
// 	int			count;

// 	count = 1;
// 	max_count = -1;
// 	loop = start;
// 	while (loop)
// 	{
// 		if (tri)
// 			loop->stay = 0;
// 		if (loop->index > max_count)
// 		{
// 			max_count = loop->index;
// 			count++;
// 			if (tri)
// 				loop->stay = 1;
// 		}
// 		loop = loop->next;
// 		if (loop == NULL)
// 			loop = st;
// 		if (loop == start)
// 			break ;
// 		// printf("count inside loop_loop = %d\n", count);
// 	}
// 	// printf("count inside loop_loop = %d\n", count);
// 	return (count);
// }


// int		get_max_sorted(t_stack *first, int trig)
// {
// 	t_stack	*tmp;
// 	t_stack	*stay;
// 	int		max;
// 	int		count;

// 	max = 0;
// 	tmp = first;
// 	while (tmp)
// 	{
// 		count = loop_stack(first, tmp, 0);
// 		if (count > max)
// 		{
// 			max = count;
// 			stay = tmp;
// 		}
// 		tmp = tmp->next;	
// 	}
// 	if (trig)
// 		loop_stack(first, stay, 1);
// 	return (max);
// }

t_stack		*get_max_sorted(t_stack **first)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		n;

	tmp = (*first);
	while (tmp)
	{
		tmp->nb_team = 1;
		tmp2 = tmp->next;
		n = tmp->number;
		if (!tmp2)
			tmp2 = (*first);
		while (tmp2->number != tmp->number)
		{
			if (n < tmp2->number)
			{
				tmp->nb_team++;
				printf("number = %d, tmp2->number = %d, NB_TEAM = %d\n", tmp->number, tmp2->number, tmp->nb_team);
				n = tmp2->number;
			}
			tmp2 = tmp2->next;
			if (!tmp2)
				tmp2 = (*first);
		}
		tmp = tmp->next;
	}
// 	printf("\n\n\ntmp->number = %d\n", tmp->number);
	return (tmp);
}

// int		swapable(t_stack *stack)
// {
// 	int		w1_i;
// 	int		w2_i;
// 	t_stack	w1;
// 	t_stack	w2;

// 	w1.next = &w2;
// 	w1.index = stack->next->index;
// 	w2.next = stack->next->next;
// 	w2.index = stack->index;
// 	w1_i = get_max_sorted(&stack);
// 	w2_i = get_max_sorted(&(w1));
// 	// printf("w1_i = %d\n, w2_i = %d\n", w1_i, w2_i);
// 	if (w2_i > w1_i)
// 		return (1);
// 	return (0);
// }

t_stack		*ft_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;
	
	tmp = (stack);
	max = tmp;
	while (tmp)
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
	min = tmp;
	while (tmp)
	{
		if (tmp->number < min->number)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

// minimum steps to move number to top of stack
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

int	ft_absolute(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}




void	init_sorter(t_stack **st_a)
{
	get_max_sorted(st_a);
	printf("max_number_team ecart here %d\n", (*st_a)->nb_team);
	(*st_a)->size = ft_size_stack(st_a);
	printf("size stack here %d\n", (*st_a)->size);
}

// Just to clear my mind : 
// do a loop inside a loop -> big loop go through the whole stack until it meets itself
// little loop 

void	sorter(t_stack **st_a, t_stack **st_b)
{
	int		gap;
	
	init_sorter(st_a);
	printf("nb_team = %d\n", (*st_a)->nb_team);
	while ((*st_a)->size > (*st_a)->nb_team)
	{
		printf("Number now is = %d, and nb_team max sorted number is = %d\n", (*st_a)->number, (*st_a)->nb_team);
		gap = ft_min_steps((*st_a), (*st_a)->index);
		// if ((*st_a) && swapable((*st_a)))
		// {
		// 	ft_swap(&(*st_a), 'a');
		// 	(*st_a)->nb_team = get_max_sorted(st_a);
		// }
		// else 
		if ((*st_a) && !(*st_a)->stay && gap == 0)
		{
			ft_push(st_a, st_b, 'b');
			((*st_a)->size)--;
		}
		else
			break ;
		// else
		// {
		// 	// ft_rotate(st, )
		// }
	}
	printf("Now push back numbers in stack_b back instack_a\n");
	// caculate_b(st_a,);
}