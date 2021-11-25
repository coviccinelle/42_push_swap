/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:33:07 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/11 12:33:31 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

    // ft_find_pivot(stack_a); //Find the biggest ecart to be the reference
 	// ft_not_sorted(stack_a); // Find numbers to push in stack_b
 	// ft_index(stack_a); // define index for elements -> reference = 0, under len/2 = -index
	// ft_adap_index(stack_a); // change index, for under len/2, after reference = - index...
 	// ft_push_in_b(stack_a, stack_b); // push not_sorted in stack_b
	// ft_reset_index(stack_a); // reset index in stack_a


// TODO: - create a big loop
// - Create another loop to find the list most sorted to stock
// - Swap if needed
// - Push the rest in stack_b
// - Caculate to find the place in a
// - Caculate to find the mi_steps needed to push back in place
// - Push back in a


int		ft_sorted(t_stack **stack_a)
{
	t_stack		*tmp;

	tmp = (*stack_a);
	while (tmp->next->next)
	{
		while (tmp->next->next && (tmp->number < tmp->next->number))
			tmp = tmp->next;
		if (tmp->number > tmp->next->number)
			return (0);
	}
	return (1);
}

void		ft_index(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->index = i;
		stack_a = stack_a->next;
		i++;
	}
}

int	init_max_sorted(t_stack **first)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		n;

	tmp = (*first);
	while (tmp)
	{
		tmp->nb_team = 1;
		tmp2 = tmp->next;
		n = tmp->number;
		if (!tmp2)
			tmp2 = (*first);
		while (tmp2->number != tmp->number)
		{
			if (n < tmp2->number)
			{
				tmp->nb_team++;
				// printf("number = %d, tmp2->number = %d, NB_TEAM = %d\n", tmp->number, tmp2->number, tmp->nb_team);
				n = tmp2->number;
			}
			tmp2 = tmp2->next;
			if (!tmp2)
				tmp2 = (*first);
		}
		tmp = tmp->next;
	}
// 	printf("\n\n\ntmp->number = %d\n", tmp->number);
	return (0);
}


int	get_max_nb_team(t_stack **stack)
{
	t_stack		*tmp;
	int			max;

	tmp = (*stack);
	max = 0;
	while (tmp)
	{
		if (tmp->nb_team > max)
			max = tmp->nb_team;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*get_head_stay(t_stack **st_a)
{
	int			max;
	t_stack		*tmp;

	tmp = (*st_a);
	max = get_max_nb_team(st_a);
	while (tmp)
	{
		if ((tmp->nb_team) == max)
		{
			tmp->stay = 1;
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_stack	*get_p_number(t_stack **st_a, int n)
{
	t_stack		*tmp;

	tmp = (*st_a);
	while (tmp)
	{
		if ((tmp->nb_team) == n)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	show_stay(t_stack **st)
{
	t_stack	*tmp;

	tmp = (*st);
	while (tmp)
	{
		printf("Show stay : tmp->number = %d, tmp->index = %d, tmp->stay = %d\n", tmp->number, tmp->index, tmp->stay);
		tmp = tmp->next;
	}
}

void	get_stay(t_stack **st, t_stack *first)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		n;

	tmp = first;
	while (tmp == first)
	{
		tmp2 = tmp->next;
		n = tmp->number;
		if (!tmp2)
			tmp2 = (*st);
		while (tmp2->number != tmp->number)
		{
			if (n < tmp2->number)
			{
				tmp2->stay = 1;
				printf("Get_stay : tmp->number = %d, tmp2->number = %d, tmp->stay = %d\n\n", tmp->number, tmp2->number, tmp->stay);
				n = tmp2->number;
			}
			tmp2 = tmp2->next;
			if (!tmp2)
				tmp2 = (*st);
		}
		tmp = tmp->next;
	}
}

void	init_stay(t_stack **st)
{
	t_stack	*tmp;

	tmp = (*st);
	while (tmp)
	{
		tmp->stay = 0;
		tmp = tmp->next;
	}
}

t_stack		*ft_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;
	
	tmp = (stack);
	max = tmp;
	while (tmp)
	{
		if (tmp->number > max->number)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*ft_min(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = stack;
	min = tmp;
	while (tmp)
	{
		if (tmp->number < min->number)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

// minimum steps to move number to top of stack
int		ft_min_steps(t_stack *stack, int index)
{
	int			step;

	step = 0;
	if (index <= (ft_size_stack(&stack) / 2))
		step = index;
	else if (index > (ft_size_stack(&stack) / 2))
		step = ft_size_stack(&stack) - index;
	return (step);
}

int	ft_absolute(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	init_sorter(t_stack **st_a)
{
	t_stack	*tmp;

	init_max_sorted(st_a);
	printf("max_number_team ecart here %d\n", get_max_nb_team(st_a));
	tmp = get_head_stay(st_a);
	printf("Head of list stay is = %d\n", tmp->number);
	get_stay(&(*st_a), tmp);
	ft_index(*st_a);
	show_stay(st_a);
	(*st_a)->size = ft_size_stack(st_a);
	printf("size stack here %d\n", (*st_a)->size);
}



// void	init_sorter_2(t_stack **st_a, **st_b)
// {
// 	t_stack		*tmp_a;
// 	t_stack		*tmp_b;
// 	int			gap_b;
// 	int			gap_a;
// 	int			gap;

// }


int		done_push_in_b(t_stack *st)
{
	t_stack	*tmp;

	tmp = st;
	while (tmp)
	{
		if (tmp->stay == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}


// return a number after tmp_b = The one should be on top of stack_a
int	ft_sandwich(t_stack *tmp_b, t_stack **st_a)
{
	t_stack		*tmp_a;
	t_stack		*tmp2_a;
	t_stack		*min_a;
	t_stack		*max_a;
	
	tmp_a = (*st_a);
	
	while (tmp_a)
	{
		min_a = ft_min(tmp_a);
		max_a = ft_max(tmp_a);

		if (tmp_b->number < min_a->number)
		{
			return (min_a->number);
			printf("\n\n\n ------ SANDWICH here :  tmp2_a = %p, tmp2_a = %d\n", tmp2_a, min_a->number);
		}
		if (tmp_b->number > max_a->number)
			return  (max_a->number);
		// TODO: Incase it's bigger than all numbers in stack_a

		tmp2_a = tmp_a->next;
		printf("tmp_a->number = %d, tmp_b->number = %d, tmp2_a->number = %d\n", 
		tmp_a->number, tmp_b->number, tmp2_a->number);
		if (!tmp2_a)
			tmp2_a = (*st_a);
		if (tmp_a->number < tmp_b->number && tmp_b->number < tmp2_a->number)
		{
			printf("\n\n\n SANDWICH\n");
			printf("\n\n ------ SANDWICH here: tmp2_a->number = %d\n", tmp2_a->number);
			return (tmp2_a->number);
			printf("here\n\n\n\n");
			break ;
		}
		printf("here\n\n\n\n");
		tmp_a = tmp_a->next;
	}
	return (-999);
}


// to calculate steps for each number in st_b
void	set_gap_b(t_stack **st_a, t_stack **st_b)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	t_stack	*p_top_a;
	int		gap_a;
	int		gap_b;
	int		gap;
	int		top_a;

	tmp_b = (*st_b);
	tmp_a = (*st_a);
	ft_index(tmp_b);
	
	while (tmp_b)
	{
		ft_index(tmp_a);
		tmp_b->gap = 0;
		top_a = ft_sandwich(tmp_b, &tmp_a);

		p_top_a = get_p_number(st_a, top_a);
		printf("top_a (the number should be on top of a) = %d, pointer top a = %d\n", top_a, p_top_a->number);
		

		// Probem in here
		gap_a = ft_min_steps(tmp_a, p_top_a->index);


		printf("gap_a (minimun steps to put top_a on top) = %d, p_top_a->index = %d, size_stack %d\n",
		gap_a, p_top_a->index, ft_size_stack(&tmp_a));
		gap_b = ft_min_steps(tmp_b, tmp_b->index);
		printf("gap_b (number of steps to put b on top) is  = %d, size_stack_b = %d\n", gap_b, ft_size_stack(&tmp_b));
		gap = gap_a + gap_b + 1;

		tmp_b->gap = gap;
		printf("Total number of gap for this number in b is GAP = %d (= gap a:%d + gap_b: %d + 1)\n", gap, gap_a, gap_b);

		// break ;
		tmp_b = tmp_b->next;
	}
}



int	ft_compare_b_int(t_stack **st_b)
{
	t_stack	*tmp;
	int		min;

	min = 999;
	tmp = (*st_b);
	while (tmp)
	{
		if (tmp->gap < min)
			min = tmp->gap;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*ft_compare_b(t_stack **st_b)
{
	int		min;
	t_stack	*tmp;

	tmp = (*st_b);
	min = ft_compare_b_int(st_b);
	while (tmp)
	{
		if (tmp->gap == min)
			return(tmp);
		tmp = tmp->next;
	}
	return (NULL);
}


void	ft_sorter_p2(t_stack **st_a, t_stack **st_b)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	t_stack		*min_b;

	printf("Let's take a look in stack_a\n\n");
	ft_display_stack(*st_a);
	tmp_a = *(st_a);
	tmp_b = *(st_b);

	while (tmp_b)
	{
		set_gap_b(&tmp_a, &tmp_b);

		// top_a = ft_sandwich(tmp_b, &tmp_a); // number under tmp_b in stack a
		// printf("\n\n\nOk here 2 sandwich\n tmp2_a->number (top_a) = %d\n", top_a);
		// tmp2_a = get_p_number(&tmp_a, top_a);
		
		// gap_a = ft_min_steps(tmp2_a, tmp2_a->index);// tmp2_a on top;
		// printf("Let's take a look in stack_a\n");
		// ft_display_stack(tmp_a);

		// printf("Let's take a look in tmp2_a\n");
		// ft_display_stack(tmp2_a);


		// gap_b = ft_min_steps(tmp_b, tmp_b->index);// tmp_b on top;
		// tmp_b->gap = gap_a + gap_b + 1;
		min_b = ft_compare_b(&tmp_b);
		printf("min_b->number(the smallest steps in b) is = %d\n", min_b->number);
		// get_num_on_top(&min_b, min_b->index, gap_b);
		// get_num_on_top(&tmp2_a, tmp2_a->index, gap_a);
		// ft_push(&tmp_b, &tmp_a, 'a');
	
		printf("AUKAYYY : get 2 numbers on top and push\n");
		break ;
		tmp_b = tmp_b->next; // not yet
	}
}

void	sorter(t_stack **st_a, t_stack **st_b)
{
	t_stack	*tmp;

	tmp = (*st_a);
	init_sorter(&tmp);
	while (tmp)
	{
		while (tmp)
		{
			if (tmp->stay == 0)
			{
				ft_push(&tmp, st_b, 'b');
				printf("Sorter 1 : tmp->number = %d, tmp->index = %d, tmp->stay = %d\n\n", tmp->number, tmp->index, tmp->stay);
				break ;
			}
			else if (tmp->stay == 1)
			{
				ft_rotate(&tmp, 'a');
				printf("Sorter 2 : tmp->number = %d, tmp->index = %d, tmp->stay = %d\n", tmp->number, tmp->index, tmp->stay);
				break ;
			}
			// tmp = tmp->next;
		}
		if (done_push_in_b(tmp))
			break ;
	}
	printf("\n\n\n ------------ ALGO_2  ------------- \n\n => Now calculate and push back numbers in b to a\n");
	ft_sorter_p2(&tmp, st_b);
}

// TODO:
// 1. Find tmp < number && number < tmp2 in stack_a
// 2. int gap = ft_min_steps(tmp2 on top) + ft_min_steps(number on top b) + 1;
// 3. Compare all number->gap in st_b and push_back in b

// TODO:
// - Step to push back in st_a:
// 1. ft_sandwich(tmp_b, tmp_a, tmp2_a); => return pointer on tmp2;
// 2. => get_num_on_top (tmp_b);
// 3. => get_num_on_top (tmp2_a);
// 4. => ft_psuh(tmp_b on top of a);



// => I can do this in 1 hour!!! Come on you can do this.

// // to  bring him on top and push every time ->reset index and min_step

// 		ft_index(*stack_a);
// 		tmp = (*stack_a);
// 		gap = ft_min_steps(*stack_a, min_2->index);
// 		get_num_on_top(stack_a, min_2->index, gap);
// 		ft_push(stack_a, stack_b, 'b');