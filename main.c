/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:29:52 by thi-phng          #+#    #+#             */
/*   Updated: 2021/12/02 11:58:27 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_env	f;

	ft_init(&f);
	if (ac > 1)
	{
		if (ac == 2)
		{
			if (ft_parsing_1(av[1], &(f.stack_a), 0))
				ft_algo(&(f.stack_a), &(f.stack_b));
		}
		if (ac > 2)
		{
			if (ft_parsing_multi_2(ac, &*av, &(f.stack_a), 1))
				ft_algo(&(f.stack_a), &(f.stack_b));
		}
	}
	return (0);
}
