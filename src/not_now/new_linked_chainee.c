/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_linked_chainee.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 11:13:05 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/13 13:54:20 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_stack
{
	int		number;
	void	*next;
}				t_stack;


void	ft_new_element(t_stack	**stack, int n)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = (*stack);
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return ;
	if (*stack == NULL)
	{
		*stack = new;
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

int		ft_size_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

//	stack = NULL;
	tmp = NULL;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}


int		ft_display_stack(t_stack *stack)
{
	//t_stack		*stack;
	t_stack		*tmp;

//	tmp = NULL;
	stack = NULL;
	while (tmp)
	{
		printf("%d\n", tmp->number);
		tmp = tmp->next;
	}
	return (0);
}


int main ()
{
//		display
	t_stack *stack;
	//t_stack *temp;

	//stack = NULL;
	//temp = Pile;
	ft_new_element(&stack, 12);
	ft_new_element(&stack, 15);
	ft_new_element(&stack, 17);
	
	//temp = stack;
	printf("Pass here\n");
	
	printf("%d\n", ft_size_stack(stack));
	ft_display_stack(stack);
	/*while (temp)
	{
		printf("%d\n", temp->number);
		temp = temp->next;
	}*/
	//printf("%d\n", ft_size_stack(&stack));
	return (0);
}
