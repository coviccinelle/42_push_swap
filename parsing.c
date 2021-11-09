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

// PARSING PART //


int	ft_parsing_1(char *str)
{
	int	i;
	int	n;
	t_stack **stack = NULL;
	t_stack **stack_b = NULL;

	*stack = NULL;
	*stack_b = NULL;
	i = 0;
	if (!ft_int_exist(str) || ft_invalid_char(str))
	{
		printf("Error\nThere's an outsider : an invalid char inside\n");
		return (0);
	}
	while (str[i] &&(i <= ft_strlen(str)))
	{
		n = ft_atoi_1(&str[i]);
		ft_new_element(stack, n);
		printf("n = ft_atoi_1(&str[i]) =  %d\n", n);
		while (str[i] == ' ')
			i++;
		while (find_me(str[i], "-0123456789"))
			i++;
		if (str[i] == ' ' && !ft_int_exist(&str[i]))
			break ;
		i++;
	}
	printf("Size of stack = %d\n", ft_size_stack(stack));
	if (ft_doublons(*stack))
		return (0);
	else
	{
		printf("Display stack_a\n");
		ft_display_stack(*stack);
		printf("\n-------\n");
		ft_algo(stack, stack_b);
		printf("\n-------\n");
	}
	return (0);
}

int	ft_parsing_multi_2(int ac, char **av)
{
	int		i;
	int		n;
	t_stack **stack = NULL;
	t_stack **stack_b = NULL;

//	*stack_b = NULL;
//	*stack = NULL;
	printf("hello allo allo inside parsing_multi\n");
	i = 1;
	printf("ac = %d\n", ac);
	while (i < ac)
	{
		printf("hello allo allo dans boucles \n");
		printf("ft_invalid_char = %i\n", ft_invalid_char(av[1]));
		printf("ft_all_blank = %i\n", ft_all_blank(av[1]));
		printf("ft_2nb_stick = %i\n", ft_2nb_stick(av[1]));
		if (ft_invalid_char(av[i]) || ft_all_blank(av[i]) || ft_2nb_stick(av[i]))
		{
			printf("Error\nWrong Wroong argruments\n");
			return (0) ;
		}
		else
		{	
			n = ft_atoi_1(av[i]);
			printf("n = ft_atoi_1(&str[i]) =  %d\n", n);
			ft_new_element(stack, n);
			printf("n = ft_atoi_1(&str[i]) =  %d\n", n);
		}
		i++;
	}
	if (ft_doublons(*stack))
		return (0);
	else
	{
		printf("stack_a\n");
		ft_display_stack(*stack);
		printf("-------\n");
		printf("---Starting algo----\n");
		ft_algo(stack, stack_b);
		printf("\n----done algo---\n");
		/*printf("stack_a\n");
		ft_display_stack(stack);
		printf("stack_b\n");
		ft_display_stack(stack_b);
		ft_swap(stack, 'a');
		printf("\n-------\n");*/
	}
	return (0);
}
