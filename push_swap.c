/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:09:01 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/19 18:51:36 by thi-phng         ###   ########.fr       */
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
	int		invalid_char;
}				t_stack;


// UTILS //
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



// END OF UTILS //

// LISTE CHAINEE starts here //
//
//
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
	while (str[i] && (i <= ft_strlen(str)))
	{
		n = ft_atoi_1(&str[i]);
		ft_new_element(&Stack, n);
		//ft_display_stack(Stack);
		printf("n = ft_atoi_1(&str[i]) =  %d\n", n);
		while (str[i] == ' ')
			i++;
		while (find_me(str[i], "-0123456789"))
			i++;
		if (str[i] == ' ' && !ft_int_exist(&str[i]))
			return (0);
		i++;
	//	ft_display_stack(Stack);
	//
	
	// It's not displaying the stack in here  //
	// AHHHHHHH //
	}
	printf("HEllo?!");
	ft_display_stack(Stack);
	return (0);
}

int	ft_parsing_multi_2(int ac, char **av)
{
	int		i;
	int		n;
	t_stack *Stack;

	Stack = NULL;
	i = 1;
	while (i < ac)
	{
		if (ft_invalid_char(av[i]) || ft_all_blank(av[i]))
		{
			printf("Error\nWrong Wroong argruments\n");
			return (0) ;
		}
		else
		{
			n = ft_atoi_1(av[i]);
			ft_new_element(&Stack, n);
		//	printf("n = %d\n", n);
			printf("n = ft_atoi_1(&str[i]) =  %d\n", n);
		}
		i++;
	}
	ft_display_stack(Stack);
	return (0);
}

// NO NEED for now //
void	init(t_stack *f)
{
	f->invalid_char = 0;
}


int	main(int ac, char **av)
{
	t_stack f;

	init(&f);
	if (ac > 1)
	{
		if (ac == 2)
		{
			printf("All in one agrument => Parsing for only one\n");
			ft_parsing_1(av[1]);
//			ft_start_algo();
			return (0);
		}
		if (ac > 2)
		{
			printf("Oh oh there's more to come => Parsing for a lot at the same time\n");
			ft_parsing_multi_2(ac, &*av);
//			ft_start_algo();
		}
//		ft_free_stack(a vs b);
	}
	return (0);
}

