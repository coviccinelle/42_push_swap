/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:09:01 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/02 13:49:01 by thi-phng         ###   ########.fr       */
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
		tmp2 = Stack->next->next;
//		tmp2 = tmp2->next;
		Stack = Stack->next;
		Stack->next = tmp1;
		tmp1->next = tmp2;
	}
	printf("\n -----s%c-----\n", c);
	ft_display_stack(Stack);
}

void	ft_ss(t_stack *Stack_a, t_stack *Stack_b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_size_stack(&Stack_a) >= 2)
	{
		tmp1 = Stack_a;
		tmp2 = Stack_a->next;
		tmp2 = tmp2->next;
		Stack_a = Stack_a->next;
		Stack_a->next = tmp1;
		tmp1->next = tmp2;
	}
	if (ft_size_stack(&Stack_b) >= 2)
	{
		tmp1 = Stack_b;
		tmp2 = Stack_b->next;
		tmp2 = tmp2->next;
		Stack_b = Stack_b->next;
		Stack_b->next = tmp1;
		tmp1->next = tmp2;
	}
	printf("ss\n");
	printf("Stack_a swaped\n");
	ft_display_stack(Stack_a);
	printf("Stack_b swaped\n");
	ft_display_stack(Stack_b);
}


int	ft_rotate(t_stack *Stack, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp_curs;

	if (!Stack)
		return (0);
	else
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
	return (1);
}

int	ft_rr(t_stack *Stack_a, t_stack *Stack_b)
{
	t_stack	*tmp1;
	t_stack	*tmp_curs;

	if (Stack_a)
	{
		tmp1 = Stack_a;
		tmp_curs = Stack_a;
		Stack_a = Stack_a->next;
		while (tmp_curs->next)
			tmp_curs = tmp_curs->next;
		tmp_curs->next = tmp1;
		tmp1->next = NULL;
	}
	if (Stack_b)
	{
		tmp1 = Stack_b;
		tmp_curs = Stack_b;
		Stack_b = Stack_b->next;
		while (tmp_curs->next)
			tmp_curs = tmp_curs->next;
		tmp_curs->next = tmp1;
		tmp1->next = NULL;
	}
	printf("-----rr-----\nStack_a rotated =\n");
	ft_display_stack(Stack_a);
	printf("\nStack_b rotated =\n");
	ft_display_stack(Stack_b);
	return (1);
}


int	ft_reverse_rotate(t_stack *Stack, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp_run;

	if (!Stack)
		return (0);
	else
	{
		tmp1 = Stack;
		while (Stack->next)
		{
			tmp_run = Stack;
			Stack = Stack->next;
		}
		tmp_run->next = NULL;
		Stack->next = tmp1;
	}
	printf("rr%c\n", c);
	ft_display_stack(Stack);
	return (1);
}


int	ft_rr_ro(t_stack *Stack)
{
	t_stack	*tmp1;
	t_stack	*tmp_run;

	if (!Stack)
		return (0);
	else
//	if (Stack)
	{
		tmp1 = Stack;
		while (Stack->next)
		{
			tmp_run = Stack;
			Stack = Stack->next;
		}
		tmp_run->next = NULL;
		Stack->next = tmp1;
	}
	printf("stack reverse rotatedi = \n");
	ft_display_stack(Stack);
	return (1);
}


void	ft_rrr(t_stack *Stack_a, t_stack *Stack_b)
{
	if (Stack_a)
		ft_rr_ro(Stack_a);
	if (Stack_b)
		ft_rr_ro(Stack_b);
	printf("rrr\n");
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
		st_r = tmp1;
		tmp1->next = tmp2;
	}
	printf("\n -----Satck  b   %c-----\n", c);
	ft_display_stack(st_t);
	printf("\n -----p%c-----\n", c);
	ft_display_stack(st_r);
	return (0);
}


// DOUBLONS PART //
//
//
int	ft_doublons(t_stack *Stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = Stack;
//	if (ft_size_stack(Stack) < 2 || !Stack || !tmp1 || !tmp2)
	if (!Stack || !tmp1 || !tmp1->next)
		return (0);
	tmp2 = tmp1->next;
//	while (tmp1->next)
	while (tmp1)
	{
	//	while(tmp2->next)
		while (tmp2)
		{
			if (tmp1->number == tmp2->number)
			{
				printf("Error\nDouble number\n");
				return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		if (tmp1->next == NULL) // ???
			break;
		tmp2 = tmp1->next;
	}
	return (0);
}





// PARSING PART //
void	init(t_env *f)
{
	f->Stack_a = NULL;
	f->Stack_b = NULL;
}


int	main(int ac, char **av)
{
	t_env f;

	init(&f);
	if (ac > 1)
	{
		if (ac == 2)
		{
			printf("All in one agrument => Parsing for only one\n");
			if (ft_parsing_1(av[1]);
//			ft_start_algo();
			return (0);
		}
		if (ac > 2)
		{
			printf("Oh oh there's more to come => Parsing for a lot at the same time\n");
			if (ft_parsing_multi_2(ac, &*av))
				ft_algo(f.Stack_a, f.Stack_b);
//			ft_start_algo();
		}
//		ft_free_stack(a vs b);
	}
	return (0);
}

