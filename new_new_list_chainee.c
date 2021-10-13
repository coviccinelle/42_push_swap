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


int main ()
{
	t_stack *Stack;

	Stack = NULL;
	ft_new_element(&Stack, 12);
	ft_new_element(&Stack, 15);
	ft_new_element(&Stack, 17);
	
	printf("size Stack =  %d\n", ft_size_stack(Stack));
	ft_display_stack(Stack);
	return (0);
}
