/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:06:45 by thi-phng          #+#    #+#             */
/*   Updated: 2021/12/04 10:18:29 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_init_elem(t_stack *new)
{
	new->stay = 0;
	new->nb_team = 1;
	new->index = 0;
}
