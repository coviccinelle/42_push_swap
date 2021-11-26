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

void	ft_algo_3(t_stack **st)
{
	int		nd;
	int		rd;

	nd = (*st)->next->number;
	rd = (*st)->next->next->number;
	if (!ft_sorted(st))
	{
		if ((*st)->number > nd && nd < rd && rd > (*st)->number)
			ft_swap(st, 'a');
		else if ((*st)->number > nd && nd > rd && rd < (*st)->number)
		{
			ft_swap(st, 'a');
			ft_reverse_rotate(st, 'a');
		}
		else if ((*st)->number > nd && nd < rd && rd < (*st)->number)
			ft_rotate(st, 'a');
		else if ((*st)->number < nd && nd > rd && rd > (*st)->number)
		{
			ft_swap(st, 'a');
			ft_rotate(st, 'a');
		}
		else if ((*st)->number < nd && nd > rd && rd < (*st)->number)
			ft_reverse_rotate(st, 'a');
	}
}

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

void	ft_algo_big(t_stack **st_a, t_stack **st_b)
{
	t_stack *max;
	t_stack *min;
	t_stack *last;
	t_stack	*tmp;
	t_stack	*tmp_b;

	tmp = (*st_a);
	tmp_b = (*st_b);
	if (!ft_sorted(&tmp))
	{
		max = ft_max(tmp);
		last = get_last(tmp);
		printf("last_element in stack_a is %d\n", last->number);
		printf("maxx_element in stack_a is %d\n", max->number);
		min = ft_min(tmp);
		printf("minn_element in stack_a is %d\n", min->number);
		sorter(&tmp, &tmp_b);
		
		//Problem is here 
		printf("\nFINAL\nStack_a is : \n");
		ft_display_stack(tmp);
		printf("\n--At the end, stack_b is :-\n");
		ft_display_stack(tmp_b);
		printf("ft_algo_big is DONE, Duh!\n");
	}
	
}
