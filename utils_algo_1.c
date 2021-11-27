/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:06:45 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/26 17:40:08 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_max_sorted(t_stack **first)
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
				n = tmp2->number;
			}
			tmp2 = tmp2->next;
			if (!tmp2)
				tmp2 = (*first);
		}
		tmp = tmp->next;
	}
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

t_stack	*get_p_number(t_stack **st_a, int n)
{
	t_stack		*tmp;

	tmp = (*st_a);
	while (tmp)
	{
		if ((tmp->number) == n)
			return (tmp);
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
		printf("Show stay : tmp->number = %d, tmp->index = %d, tmp->stay = %d\n", tmp->number, tmp->index, tmp->stay);
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
