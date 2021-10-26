/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:48:26 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/26 16:38:13 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_me(char c, const char *str)
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

int	ft_int_exist(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (find_me(str[i], "0123456789"))
			return (str[i]);
		i++;
	}
	return (0);
}

int	ft_all_blank(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}


int	ft_atoi_1(char *str)
{
	int				i;
	unsigned long	res;
	int				neg;

	neg = 1;
	res = 0;
	i = 0;
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


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_invalid_char(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!(find_me(str[i], "- 0123456789")))
			return (1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && !(find_me(str[i + 1], "0123456789")))
			return (1);
		i++;
	}
	return (0);
}


int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
