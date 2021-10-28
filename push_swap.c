/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:09:01 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/28 18:11:42 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



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


int		ft_size_stack(t_stack **Stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *Stack;
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

//       -----  OPERATIONS FUNCTIONS -----       //
//
//
void	ft_swap(t_stack *Stack, char c)
{
	t_stack *tmp1;
	t_stack	*tmp2;

	if (ft_size_stack(&Stack) >= 2)
	{
		tmp1 = Stack;
		tmp2 = Stack->next;
		tmp2 = tmp2->next;
		Stack = Stack->next;
		Stack->next = tmp1;
		tmp1->next = tmp2;
	}
	printf("\n -----s%c-----\n", c);
	ft_display_stack(Stack);
}


void	ft_rotate_i(t_stack *Stack, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp_curs;

	if (ft_size_stack(&Stack) >= 2)
	{
		tmp1 = Stack;
		tmp_curs = Stack;
		Stack = Stack->next;
		while (tmp_curs->next)
			tmp_curs = tmp_curs->next;
		tmp_curs->next = tmp1;
		tmp1->next = NULL;
	}
	printf("\n -----r%c-----\n", c);
	ft_display_stack(Stack);
}

//St_t = Stack take;
//St_r = Stack receive;
int	ft_push(t_stack *st_t, t_stack *st_r, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	printf("\n -----ft_stack_a avant = %c-----\n", c);
	ft_display_stack(st_t);
	if (!st_t)
		return (0);
	else
	{
		tmp1 = st_t;//list_a
		tmp2 = st_r;//list_b
		st_t = st_t->next;
		//st_t = st_t->next;
		st_r = tmp1;
		tmp1->next = tmp2;
	}
	printf("\n -----Satck  b   %c-----\n", c);
	ft_display_stack(st_t);
	printf("\n -----p%c-----\n", c);
	ft_display_stack(st_r);
	return (0);
}

// PARSING PART //



int	main(int ac, char **av)
{
//	t_stack f;

//	init(&f);
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

