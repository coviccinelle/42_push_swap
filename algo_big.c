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

int	init_max_sorted(t_stack **first)
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
				// tmp->stay = 1;
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
	return (0);
}


int	get_max_nb_team(t_stack **stack)
{
	t_stack		*tmp;
	int			max;

	tmp = (*stack);
	max = 0;
	while (tmp)
	{
		if (tmp->nb_team > max)
			max = tmp->nb_team;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*get_head_stay(t_stack **st_a)
{
	int			max;
	t_stack		*tmp;

	tmp = (*st_a);
	max = get_max_nb_team(st_a);
	while (tmp)
	{
		if ((tmp->nb_team) == max)
		{
			tmp->stay = 1;
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	show_stay(t_stack **st)
{
	t_stack	*tmp;

	tmp = (*st);
	while (tmp)
	{
		printf("tmp->number = %d, tmp->stay = %d\n", tmp->number, tmp->stay);
		tmp = tmp->next;
	}
}

void	get_stay(t_stack **st, t_stack *first)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		n;

	tmp = first;
	while (tmp == first)
	{
		// tmp.stay = 0;
		tmp2 = tmp->next;
		n = tmp->number;
		if (!tmp2)
			tmp2 = (*st);
		while (tmp2->number != tmp->number)
		{
			if (n < tmp2->number)
			{
				tmp2->stay = 1;
				printf("tmp->number = %d, tmp2->number = %d, tmp->stay = %d\n\n", tmp->number, tmp2->number, tmp->stay);
				n = tmp2->number;
			}
			tmp2 = tmp2->next;
			if (!tmp2)
				tmp2 = (*st);
		}
		tmp = tmp->next;
	}
}

void	init_stay(t_stack **st)
{
	t_stack	*tmp;

	tmp = (*st);
	while (tmp)
	{
		tmp->stay = 0;
		tmp = tmp->next;
	}
}

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
	t_stack	*tmp;

	init_max_sorted(st_a);
	printf("max_number_team ecart here %d\n", get_max_nb_team(st_a));
	tmp = get_head_stay(st_a);
	printf("Head of list stay is = %d\n", tmp->number);
	get_stay(&(*st_a), tmp);
	show_stay(st_a);
	(*st_a)->size = ft_size_stack(st_a);
	printf("size stack here %d\n", (*st_a)->size);
}

// Just to clear my mind : 
// do a loop inside a loop -> big loop go through the whole stack until it meets 
// itself little loop 

void	sorter(t_stack **st_a, t_stack **st_b)
{
	int		gap;
	
	init_sorter(st_a);
	while ((*st_a)->size > (*st_a)->nb_team)
	{
		Go though the stack, if tmptmp->stay = 0 => get_num_on_top(tmptmp) =>push
		 (*st_a)->number, (*st_a)->nb_team);
		gap = ft_min_steps((*st_a), (*st_a)->index);
	 
		if ((*st_a) && !(*st_a)->stay && gap == 0)
		{
			ft_push(st_a, st_b, 'b');
			((*st_a)->size)--;
		}
		else
			break ;

	}
	printf("Now push back numbers in stack_b back instack_a\n");
	// push numbers from b back to a, in a most optimited way =>caculate_b(st_a,); 
}


// // to  bring him on top and push every time ->reset index and min_step

// 		ft_index(*stack_a);
// 		tmp = (*stack_a);
// 		min_steps = ft_min_steps(*stack_a, min_2->index);
// 		get_num_on_top(stack_a, min_2->index, min_steps);
// 		ft_push(stack_a, stack_b, 'b');