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

	tmp = stack;
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
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->number);
		tmp = tmp->next;
	}
	return (0);
}


int main ()
{
	t_stack *stack;

	stack = NULL;
	ft_new_element(&stack, 12);
	ft_new_element(&stack, 15);
	ft_new_element(&stack, 17);
	
	printf("size stack =  %d\n", ft_size_stack(stack));
	ft_display_stack(stack);
	return (0);
}
