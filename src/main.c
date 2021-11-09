#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;	

	if (ac > 1)
	{
		if (ac == 2)
		{
            // char **splitted;
            // int size;

            // splitted = ft_split(av[1], " "));
            // size = ft_strlength(*splitted);
            // ft_parsing(size, splitted)
			return (0);
		}
		if (ac > 2)
		{
			stack_a = ft_parsing(ac, av);
			if (!stack_a)
		 		return (0);
			printf(" == End of parsing:\n");
			
			ft_display_stack(stack_a);
		}
//TODO: free the stack
	}
	return (0);
}