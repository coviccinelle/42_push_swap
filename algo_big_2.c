/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:06:32 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/27 17:58:24 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



// return a number after tmp_b = The one should be on top of stack_a
int	ft_sandwich(t_stack *tmp_b, t_stack **st_a)
{
	t_stack		*tmp_a;
	t_stack		*tmp2_a;
	t_stack		*min_a;
	t_stack		*max_a;

	tmp_a = (*st_a);
	min_a = ft_min(tmp_a);
	max_a = ft_max(tmp_a);
	if (tmp_b->number < min_a->number)
		return (min_a->number);
	if (tmp_b->number > max_a->number)
		return (max_a->number);
	while (tmp_a)
	{
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
	t_stack	*p_top_a;
	int		gap_a;
	int		gap_b;
	int		top_a;

	tmp_b = (*st_b);
	ft_index(tmp_b);
	while (tmp_b)
	{
		ft_index(*st_a);
		tmp_b->gap = 0;
		top_a = ft_sandwich(tmp_b, st_a);
		p_top_a = get_p_number(st_a, top_a);
		gap_a = ft_min_steps(*st_a, p_top_a->index);
		gap_b = ft_min_steps(*st_b, tmp_b->index);
		tmp_b->gap = gap_a + gap_b + 1;
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
			return (tmp);
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
