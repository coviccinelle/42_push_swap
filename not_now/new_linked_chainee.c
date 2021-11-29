/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_linked_chainee.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 11:13:05 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/29 12:41:44 by thi-phng         ###   ########.fr       */
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

//	Stack = NULL;
	tmp = NULL;
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
	//t_stack		*Stack;
	t_stack		*tmp;

//	tmp = NULL;
	Stack = NULL;
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
	t_stack *Stack;
	//t_stack *temp;

	//Stack = NULL;
	//temp = Pile;
	ft_new_element(&Stack, 12);
	ft_new_element(&Stack, 15);
	ft_new_element(&Stack, 17);
	
	//temp = Stack;
	// printf("Pass here\n");
	
	printf("%d\n", ft_size_stack(Stack));
	ft_display_stack(Stack);
	/*while (temp)
	{
		printf("%d\n", temp->number);
		temp = temp->next;
	}*/
	//printf("%d\n", ft_size_stack(&Stack));
	return (0);
}
