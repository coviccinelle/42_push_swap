/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:38:27 by thi-phng          #+#    #+#             */
/*   Updated: 2021/12/02 11:44:50 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// printf("Note : parsing_1_agr\n");
int	ft_parsing_1(char *str, t_stack **stack_a)
{
	int	i;
	int	n;

	i = 0;
	if (!ft_int_exist(str) || ft_invalid_char(str))
	{
		printf("Error\n");
		return (0);
	}
	while (str[i] && (i <= ft_strlen(str)))
	{
		n = ft_atoi_1(&str[i]);
		ft_new_element(stack_a, n);
		while (str[i] == ' ')
			i++;
		while (find_me(str[i], "-0123456789"))
			i++;
		if (str[i] == ' ' && !ft_int_exist(&str[i]))
			break ;
		i++;
	}
	if (ft_doublons(*stack_a))
	{
		ft_free_1st(stack_a, 1);
		return (0);
	}
	return (1);
}

// printf("Note: parsing_multi_agr\n");
int	ft_parsing_multi_2(int ac, char **av, t_stack **stack_a)
{
	int		i;
	int		n;

	i = 1;
	while (i < ac)
	{
		if (ft_invalid_char(av[i]) || ft_all_blank(av[i])
			|| ft_2nb_stick(av[i]))
		{
			printf("Error\nWrong Wroong argruments\n");
			return (0);
		}
		else
		{	
			n = ft_atoi_1(av[i]);
			ft_new_element(stack_a, n);
		}
		i++;
	}
	if (ft_doublons(*stack_a))
	{
		ft_free_1st(stack_a, 1);
		return (0);
	}
	return (1);
}
