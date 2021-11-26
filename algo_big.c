/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:33:07 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/26 17:44:05 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_stay(t_stack **st, t_stack *first)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		n;

	tmp = first;
	while (tmp == first)
	{
		tmp2 = tmp->next;
		n = tmp->number;
		if (!tmp2)
			tmp2 = (*st);
		while (tmp2->number != tmp->number)
		{
			if (n < tmp2->number)
			{
				tmp2->stay = 1;
				printf("Get_stay : tmp->number = %d, tmp2->number = %d, tmp->stay = %d\n\n", tmp->number, tmp2->number, tmp->stay);
				n = tmp2->number;
			}
			tmp2 = tmp2->next;
			if (!tmp2)
				tmp2 = (*st);
		}
		tmp = tmp->next;
	}
}

// minimum steps to move number to top of stack
int	ft_min_steps(t_stack *stack, int index)
{
	int			step;

	step = 0;
	if (index <= (ft_size_stack(&stack) / 2))
		step = index;
	else if (index > (ft_size_stack(&stack) / 2))
		step = ft_size_stack(&stack) - index;
	return (step);
}

void	init_sorter(t_stack **st_a)
{
	t_stack	*tmp;

	init_max_sorted(st_a);
	printf("max_number_team ecart here %d\n", get_max_nb_team(st_a));
	tmp = get_head_stay(st_a);
	printf("Head of list stay is = %d\n", tmp->number);
	get_stay(&(*st_a), tmp);
	ft_index(*st_a);
	show_stay(st_a);
	(*st_a)->size = ft_size_stack(st_a);
	printf("size stack here %d\n", (*st_a)->size);
}

int	done_push_in_b(t_stack *st)
{
	t_stack	*tmp;

	tmp = st;
	while (tmp)
	{
		if (tmp->stay == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// return a number after tmp_b = The one should be on top of stack_a
int	ft_sandwich(t_stack *tmp_b, t_stack **st_a)
{
	t_stack		*tmp_a;
	t_stack		*tmp2_a;
	t_stack		*min_a;
	t_stack		*max_a;

	tmp_a = (*st_a);
	while (tmp_a)
	{
		min_a = ft_min(tmp_a);
		max_a = ft_max(tmp_a);
		if (tmp_b->number < min_a->number)
			return (min_a->number);
		if (tmp_b->number > max_a->number)
			return (max_a->number);
		tmp2_a = tmp_a->next;
		if (!tmp2_a)
			tmp2_a = (*st_a);
		if (tmp_a->number < tmp_b->number && tmp_b->number < tmp2_a->number)
			return (tmp2_a->number);
		tmp_a = tmp_a->next;
	}
	return (-999);
}

// to calculate steps for each number in st_b
void	set_gap_b(t_stack **st_a, t_stack **st_b)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	t_stack	*p_top_a;
	int		gap_a;
	int		gap_b;
	int		top_a;

	tmp_b = (*st_b);
	tmp_a = (*st_a);
	ft_index(tmp_b);
	
	while (tmp_b)
	{
		ft_index(tmp_a);
		tmp_b->gap = 0;
		top_a = ft_sandwich(tmp_b, &tmp_a);
		p_top_a = get_p_number(st_a, top_a);
		gap_a = ft_min_steps(tmp_a, p_top_a->index);
		gap_b = ft_min_steps(*st_b, tmp_b->index);
		tmp_b->gap = gap_a + gap_b + 1;
		// break ;
		tmp_b = tmp_b->next;
	}
}

int	ft_compare_b_int(t_stack **st_b)
{
	t_stack	*tmp;
	int		min;

	min = 999;
	tmp = (*st_b);
	while (tmp)
	{
		if (tmp->gap < min)
			min = tmp->gap;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*ft_compare_b(t_stack **st_b)
{
	int		min;
	t_stack	*tmp;

	tmp = (*st_b);
	min = ft_compare_b_int(st_b);
	while (tmp)
	{
	if (tmp->gap == min)
		return(tmp);
	tmp = tmp->next;
	}
	return (NULL);
}

void	ft_push_b_back(t_stack **tmp_b, t_stack **tmp_a, t_stack *min_b)
{
	t_stack	*top_a_to_be;
	int		top_a;
	int		gap_a;
	int		gap_b;

	ft_index(*tmp_a);
	ft_index(*tmp_b);

	top_a = ft_sandwich(min_b, tmp_a);
	top_a_to_be = get_p_number(tmp_a, top_a);
	printf("top_a_to_be->number = %d, index = %d\n", top_a_to_be->number, top_a_to_be->index);
	gap_a = ft_min_steps(*tmp_a, top_a_to_be->index);
	gap_b = ft_min_steps(*tmp_b, min_b->index);

	printf("gap_a = %d, gap_b = %d\n", gap_a, gap_b);
	get_num_on_top(tmp_a, top_a_to_be->index, gap_a);
	get_num_on_top(tmp_b, min_b->index, gap_b);

	ft_push(tmp_b, tmp_a, 'a');
}

void	ft_sorter_p2(t_stack **st_a, t_stack **st_b)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	t_stack		*min;
	int			gap_min;

	t_stack		*min_b;
	tmp_a = *(st_a);
	tmp_b = *(st_b);
	printf("\n\n\n(1) Stack___AAAA\n");
	ft_display_stack(tmp_a);
	while (tmp_b)
	{
		set_gap_b(&tmp_a, &tmp_b);
		min_b = ft_compare_b(&tmp_b);
		printf("min_b->number(the min steps needed in b) is = %d\n", min_b->number);
		ft_push_b_back(&tmp_b, &tmp_a, min_b);
	}
	if (!ft_sorted(&tmp_a))
	{
		ft_index(tmp_a);
		min = ft_min(tmp_a);
		gap_min = ft_min_steps(tmp_a, min->index);
		get_num_on_top(&tmp_a, min->index, gap_min);
	}
	*st_a = tmp_a;
	*st_b = tmp_b;
}

void	sorter(t_stack **st_a, t_stack **st_b)
{
	t_stack	*tmp;

	tmp = (*st_a);
	init_sorter(&tmp);
	while (tmp)
	{
		while (tmp)
		{
			if (tmp->stay == 0)
			{
				ft_push(&tmp, st_b, 'b');
				break ;
			}
			else if (tmp->stay == 1)
			{
				ft_rotate(&tmp, 'a');
				break ;
			}
		}
		if (done_push_in_b(tmp))
			break ;
	}
	printf("Conclution => End of part 1: stack_a (tmp) is \n");
	ft_display_stack(tmp);
	printf("Conclution => End of part 1: stack_b is \n");
	ft_display_stack(*st_b);
	
	ft_sorter_p2(&tmp, st_b);
	*st_a = tmp;
}