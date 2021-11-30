/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:33:07 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/29 14:21:11 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sorter(t_stack **st_a)
{
	t_stack	*tmp;

	init_max_sorted(st_a);
	tmp = get_head_stay(st_a);
	get_stay(&(*st_a), tmp);
	ft_index(*st_a);
	show_stay(st_a);
	(*st_a)->size = ft_size_stack(st_a);
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
	while (tmp_b)
	{
		set_gap_b(&tmp_a, &tmp_b);
		min_b = ft_compare_b(&tmp_b);
		ft_push_b_back(&tmp_b, &tmp_a, min_b);
	}
	if (!ft_sorted(&tmp_a))
	{
		ft_index(tmp_a);
		min = ft_min(tmp_a);
		gap_min = ft_min_steps(tmp_a, min->index);
		get_num_on_top(&tmp_a, min->index, gap_min, 'a');
	}
	*st_a = tmp_a;
	*st_b = tmp_b;
}

	// if (swapable(&tmp))
	// 	ft_swap(&tmp, 'a');
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
	ft_sorter_p2(&tmp, st_b);
	*st_a = tmp;
}

void	ft_algo_big(t_stack **st_a, t_stack **st_b)
{
	t_stack	*max;
	t_stack	*tmp;
	t_stack	*tmp_b;

	tmp = (*st_a);
	tmp_b = (*st_b);
	if (!ft_sorted(&tmp))
	{
		init_stay(st_a);
		max = ft_max(tmp);
		sorter(&tmp, &tmp_b);
	}
}
