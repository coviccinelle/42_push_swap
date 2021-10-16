/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:09:01 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/16 17:34:03 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
void	exit_error(char *str, t_list Stack)
{
	if (*Stack)
	{
		printf("%s\n", str);
		free(*Stack);
	}
}
*/

typedef struct	s_stack
{
	int		number;
	void	*next;
}				t_stack;

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
/*	if  (str[i] == ' '&& str[i + 1] == ' ' && !(ft_int_exist(&str[i + 1])))
	{
		res = -420;
		i++;
	}*/
//	if (res == 0 && neg == 1 && str[i] == ' ' && !ft_int_exist(&str[i]))
//	if (str[i] == ' ' && ft_all_blank(&str[i]))
//		res = -42;
			//	if ((res * neg) == 0)
	//	printf("\ninvalid atoi int = 0\n");
	return (res * neg);
}

int	ft_atoi(char *str, int *i)
{
//	int				i;
	unsigned long	res;
	int				neg;

	neg = 1;
	res = 0;
//	i = 0;
	if (!str)
		return (0);
	while (find_me(str[*i], "\t\n\v\f\r "))
		(*i)++;
	if (str[*i] == '-')
	{
		if (str[*i++] == '-')
			neg = -1;
	}
	while (find_me(str[*i], "0123456789"))
		res = res * 10 + (str[*i++] - '0');
	printf("i vaut %d\n", *i);
	return (res * neg);
}


void	ft_new_element(t_stack	**Stack, int n)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = (*Stack);
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return ;
	//Free tout si jamais il arrive pas a allouer tout //
	if (*Stack == NULL)
	{
		*Stack = new;
		new->next = NULL;
		new->number = n;
	}
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		new->number = n;
	}
}


int		ft_size_stack(t_stack *Stack)
{
	t_stack	*tmp;
	int		i;

	tmp = Stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int		ft_display_stack(t_stack *Stack)
{
	t_stack		*tmp;

	tmp = Stack;
	while (tmp)
	{
		printf("%d\n", tmp->number);
		tmp = tmp->next;
	}
	return (0);
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

int	ft_parsing_1(char *str)
{
	int	i;
	int	n;

	i = 0;
	
//	printf("i vaut %d\n", i);
	if (!ft_int_exist(str) || ft_invalid_char(str))
	{
		printf("Error\nThere's an outsider : an invalid char inside or a double int\n");
		return (0);
	}
	while (str[i] && (i <= ft_strlen(str)))
	{
	//	printf("i vaut %d\n", i);
		n = ft_atoi_1(&str[i]);
		printf("n = ft_atoi_1(&str[i]) =  %d\n", n);
		while (str[i] == ' ')
			i++;
		while (find_me(str[i], "-0123456789"))
			i++;
//		while (str[i] == ' ' && (find_me(str[i++], " ")))
//			break ;
		if (str[i] == ' ' && !ft_int_exist(&str[i]))
			break ;
		i++;
	}
	return (0);
}

int	ft_parsing_multi(char *av)
{
//	int		i;
	int		n;

//	i = 0;
//	printf("Not segfaut yet hehehe\n");
	if (ft_invalid_char(av))
	{
		printf("Error\nWrong! Wrong! It's just wroooong!\n");
		return (0);
	}
		n = ft_atoi_1(av);
	printf("n = ft_atoi_1(&str[i]) =  %d\n", n);
	return (0);
}


int	main(int ac, char **av)
{
//	t_stack *Stack;
	char	*str;
	int		i;

	str = "-28383";
	if (ac > 1)
	{
		if (ac == 2)
		{
			printf("All in one agrument => Parsing for only one\n");
			ft_parsing_1(av[1]);
			return (0);
		}
		if (ac > 2)
		{
			i = 1;
			printf("Oh oh there's more to come => Parsing for a lot at the same time\n");
			while (i < ac)
			{
				ft_invalid_char(av[i]);
					break ;
				i++;
			}
			i = 0;
			while (i < ac)
			{
				ft_parsing_multi(av[i]);
				i++;
//				return (0);
			}
		}
	}
	return (0);
}

