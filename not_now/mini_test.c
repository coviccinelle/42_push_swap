/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:58:27 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/29 12:41:27 by thi-phng         ###   ########.fr       */
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

int	ft_atoi_1(char *str)
{
	int				i;
	unsigned long	res;
	int				neg;

//	printf("str[i] = %s\n", str);
	neg = 1;
	res = 0;
	i = 0;
	if (!str)
		return (0);
	while (find_me(str[i], "\t\n\v\f\r "))
		i++;
	if (str[i] == '-')
	{
		if (str[i++] == '-')
			neg = -1;
	}
	while (find_me(str[i], "0123456789"))
		res = res * 10 + (str[i++] - '0');
	return (res * neg);
}

int	ft_invalid_double(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == str[i + j])
			return (1);
		j++;
	}
	return (0);
}



int	main()
{
	char	*str;

	str = "5 6 7  66 77 22";
	if (ft_invalid_double(str))
		printf("Error\nthere's a double int free here\n");
	if (ft_invalid_char(str))
		printf("Error\nthere's a outsider \n");
	if (!ft_invalid_char(str))
		// printf("Green light! Please pass :>\n");
	// printf("n = ft_atoi_1(str) = %d\n", ft_atoi_1(str));
	// printf("free apres avoir fini!!!\n");
	return (0);
}

