/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:38:27 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/06 18:31:04 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_parsing(int ac, char **av)
{
	int		i;
	int		n;
	t_stack *start_stack_a = NULL;
	t_stack *current_stack_a = NULL;

	i = 1;
	while (i < ac)
	{
		if (ft_invalid_char(av[i]) || ft_all_blank(av[i]) || ft_2nb_stick(av[i]))
		{
			printf("Error\nWrong Wroong argruments\n");
			return (0) ;
		}
		else
		{
			n = ft_atoi_1(av[i]);
			if (i == 1) { // first element
				current_stack_a = ft_new_element(n);
				start_stack_a = current_stack_a;
			} else {
				current_stack_a->next = ft_new_element(n);
				current_stack_a = current_stack_a->next;
			}
		}
		i++;
	}
	if (ft_doublons(start_stack_a))
		return NULL;
	return start_stack_a;
}
