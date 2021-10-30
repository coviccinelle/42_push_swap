/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:38:27 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/30 18:01:42 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PARSING PART //


int	ft_parsing_1(char *str)
{
	int	i;
	int	n;
	t_stack *Stack;

	Stack = NULL;
	i = 0;
	if (!ft_int_exist(str) || ft_invalid_char(str))
	{
		printf("Error\nThere's an outsider : an invalid char inside\n");
		return (0);
	}
	while (str[i] &&(i <= ft_strlen(str)))
	{
		n = ft_atoi_1(&str[i]);
		ft_new_element(&Stack, n);
		printf("n = ft_atoi_1(&str[i]) =  %d\n", n);
		while (str[i] == ' ')
			i++;
		while (find_me(str[i], "-0123456789"))
			i++;
		if (str[i] == ' ' && !ft_int_exist(&str[i]))
			break ;
		i++;
	}
	printf("Size of Stack = %d\n", ft_size_stack(&Stack));
	ft_display_stack(Stack);
	return (0);
}

int	ft_parsing_multi_2(int ac, char **av)
{
	int		i;
	int		n;
	t_stack *Stack;
	t_stack *Stack_b;

	Stack_b = NULL;
	Stack = NULL;
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
			ft_new_element(&Stack, n);
			ft_new_element(&Stack_b, n);
			printf("n = ft_atoi_1(&str[i]) =  %d\n", n);
		}
		i++;
	}
	printf("Stack_a\n");
	ft_display_stack(Stack);
	printf("Stack_b\n");
	ft_display_stack(Stack_b);
	//ft_swap(Stack, 'a');
//	ft_rotate_i(Stack, 'a');
	printf("\n-------\n");
//	ft_ss(Stack, Stack_b);
//	ft_reverse_rotate(Stack, 'a');
//	ft_rr_ro(Stack);
	ft_rrr(Stack, Stack_b);
//	ft_push(Stack, Stack_b, 'a');
//	printf("Stack_a ---- after\n");
//	ft_display_stack(Stack);
//	printf("Stack_b ---- after\n");
//	ft_display_stack(Stack_b);
	return (0);
}
