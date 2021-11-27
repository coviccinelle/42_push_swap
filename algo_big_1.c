/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:23:02 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/27 16:28:07 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 




int	get_num_on_top(t_stack **stack_a, int index, int min_steps)
{
	int i;

	i = min_steps;
	if (index > i)
	{
		while (i > 0)
		{
			ft_reverse_rotate(stack_a, 'a');
			i--;
		}
	}
	else if (index <= i)
	{
		while (i > 0)
		{
			ft_rotate(stack_a, 'a');
			i--;
		}
	}
	printf("done get_num_on_top\n");
	return (0);
}



void	ft_sorter_p2(t_stack **st_a, t_stack **st_b)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	t_stack		*min;
	int			gap_min;

	t_stack		*min_b;
	tmp_a = *(st_a);
	tmp_b = *(st_b);
	printf("\n\n\n(1) Stack___AAAA\n");
	ft_display_stack(tmp_a);
	while (tmp_b)
	{
		set_gap_b(&tmp_a, &tmp_b);
		min_b = ft_compare_b(&tmp_b);
		printf("min_b->number(the min steps needed in b) is = %d\n", min_b->number);
		ft_push_b_back(&tmp_b, &tmp_a, min_b);
	}
	printf("\n\n\n after Stack___AAAA\n");
	ft_display_stack(tmp_a);
	printf("\n\n\n after Stack___BBBB\n");
	ft_display_stack(tmp_b);
	printf("\n------ Done -----\n");
	

	if (!ft_sorted(&tmp_a))
	{
		ft_index(tmp_a);
		min = ft_min(tmp_a);
		gap_min = ft_min_steps(tmp_a, min->index);
		get_num_on_top(&tmp_a, min->index, gap_min);


		printf("\n\n\n STEP 3: Stack___AAAA\n");
		ft_display_stack(tmp_a);
		printf("\n\n\n STEP 3: Stack___BBBB\n");
		ft_display_stack(tmp_b);
		printf("\n------ Done STEP 3 -----\n");
	}
	*st_a = tmp_a;
	*st_b = tmp_b;
}

void	sorter(t_stack **st_a, t_stack **st_b)
{
	t_stack	*tmp;
	// t_stack	*tmp_b;

	//tmp_b = (*st_b);
	tmp = (*st_a);
	init_sorter(&tmp);
	while (tmp)
	{
		while (tmp)
		{
			if (tmp->stay == 0)
			{
				ft_push(&tmp, st_b, 'b');
				break ;
			}
			else if (tmp->stay == 1)
			{
				ft_rotate(&tmp, 'a');
				break ;
			}
		}
		if (done_push_in_b(tmp))
			break ;
	}
	printf("Conclution => End of part 1: stack_a (tmp) is \n");
	ft_display_stack(tmp);

	printf("Conclution => End of part 2: stack_b is \n");
	ft_display_stack(*st_b);
	ft_sorter_p2(&tmp, st_b);
	*st_a = tmp;
}

void	ft_algo_big(t_stack **st_a, t_stack **st_b)
{
	t_stack     *max;
	t_stack     *min;
	t_stack     *last;
	t_stack     *tmp;
	t_stack     *tmp_b;

	tmp = (*st_a);
	tmp_b = (*st_b);
	if (!ft_sorted(&tmp))
	{
		max = ft_max(tmp);
		last = get_last(tmp);
		printf("last_element in stack_a is %d\n", last->number);
		printf("maxx_element in stack_a is %d\n", max->number);
		min = ft_min(tmp);
		printf("minn_element in stack_a is %d\n", min->number);
		sorter(&tmp, &tmp_b);
		printf("\nFINAL\nStack_a is : \n");
		ft_display_stack(tmp);
		printf("\n--At the end, stack_b is :-\n");
		ft_display_stack(tmp_b);
		printf("ft_algo_big is DONE, Duh!\n");
	}
}
