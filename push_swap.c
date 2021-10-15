/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:09:01 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/15 16:05:40 by thi-phng         ###   ########.fr       */
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




int	ft_atoi(char *str, int *i)
{
	unsigned long	res;
	int				neg;

//	printf("str[i] = %s\n", str);
	neg = 1;
	res = 0;
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

void	ft_new_element(t_stack	**Stack, int n)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = (*Stack);
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return ;
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








int	ft_parsing_1(char *str)
{
	int	i;
	int	n;

	i = 0;
	
	printf("i vaut %d\n", i);
	if (!ft_int_exist(str))
		return (0);
	while (str[i])
	{
		printf("i vaut %d\n", i);
		n = ft_atoi(str, &i);
		i++;
		if (!str[i])
			break ;
		printf("atoi here : %d\n", n);
//		printf("Where am I? %c\n", str[i]);
	}
	return (0);
}





int	main(int ac, char **av)
{
//	t_stack *Stack;
	char *str;

	str = "-28383";
	printf("str\n");
	printf("str = %d\n", ft_atoi(str, 0));
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
			printf("Oh oh there's more to come => Parsing for a lot at the same time\n");
//			ft_parsing_multi(av[1]);
			return (0);
		}
	}
	return (0);
}



// Parsing order for only 1 agrument //
// 1. C
