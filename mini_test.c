/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:58:27 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/16 15:04:30 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	find_me(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (c);
		i++;
	}
	return (0);
}


int	ft_invalid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!find_me(str[i], "- 0123456789"))
			return (1);
		i++;
	}
	return (0);
}

int	main()
{
	char	*str;

	str = "18    15     - 35    2   ";
	if (ft_invalid_char(str))
		printf("Error\nthere's a outsider\n");
	if (!ft_invalid_char(str))
		printf("Green light! Please pass :>\n");
	return (0);
}

