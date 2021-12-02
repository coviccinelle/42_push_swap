/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:38:27 by thi-phng          #+#    #+#             */
/*   Updated: 2021/12/02 18:27:19 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	invalid_min_max_int(long n, t_stack **st_a, int i)
{
	if (i == 1)
	{
		if (n == -2147483649)
		{
			ft_free_1st(st_a, 1);
			return (1);
		}
		return (0);
	}
	else if (i == 0)
	{
		if (ft_doublons(*st_a))
			ft_free_1st(st_a, 1);
		return (0);
	}
	return (0);
}

// printf("Note : parsing_1_agr\n");
int	ft_parsing_1(char *str, t_stack **stack_a, int i)
{
	long	n;

	if ((!ft_int_exist(str) && !ft_all_blank(str)) || ft_invalid_char(str))
	{
		printf("Error\n");
		return (0);
	}
	while (str[i] && (i <= ft_strlen(str)))
	{
		n = ft_atoi_1(&str[i]);
		if (invalid_min_max_int(n, stack_a, 1))
			return (0);
		if (!ft_new_element(stack_a, n))
			return (0);
		while (find_me(str[i], "-0123456789"))
			i++;
		if (str[i] == ' ' && !ft_int_exist(&str[i]))
			break ;
		i++;
	}
	if (invalid_min_max_int(n, stack_a, 0))
		return (0);
	return (1);
}

int	invalid_agr_2(char *str, t_stack **stack_a)
{
	if (ft_invalid_char(str) || ft_all_blank(str)
		|| ft_2nb_stick(str))
	{
		ft_free_1st(stack_a, 1);
		return (1);
	}
	return (0);
}

// printf("Note: parsing_multi_agr\n");
int	ft_parsing_multi_2(int ac, char **av, t_stack **stack_a, int i)
{
	long int		n;

	while (i < ac)
	{
		if (invalid_agr_2(av[i], stack_a))
			return (0);
		else
		{	
			n = ft_atoi_1(av[i]);
			if (n == -2147483649)
			{
				ft_free_1st(stack_a, 1);
				return (0);
			}
			if (!ft_new_element(stack_a, n))
				return (0);
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
