/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:09:12 by thi-phng          #+#    #+#             */
/*   Updated: 2021/11/05 17:58:02 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_stack
{
	int				number;
	struct s_stack	*next;
	int				index;
	int				diff;
	int				stay;
	int				max_sorted;
}				t_stack;


typedef struct	s_env
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_env;

// UTILS //
int	find_me(char c, const char *str);
int	ft_int_exist(char *str);
int	ft_all_blank(char *str);
int	ft_atoi_1(char *str);
int	ft_strlen(char *str);
int	ft_invalid_char(char *str);
int	ft_smaller(int a, int b);
int	ft_bigger(int a, int b);
int	ft_2nb_stick(char *str);

// PARSING PARTs //
int	ft_parsing_1(char *str, t_stack **stack_a);
int	ft_parsing_multi_2(int ac, char **av, t_stack **stack_a);

void	ft_free_ck(t_stack **list_a);
int		ft_check_double(t_stack **list_a);



// LISTE CHAINEE starts here //
void	ft_new_element(t_stack	**stack, int n);
int		ft_size_stack(t_stack **stack);
void	ft_display_stack(t_stack *stack);
void	ft_display_2_stacks(t_stack *stack_a, t_stack *stack_b);
int		ft_doublons(t_stack *stack);

// tools in algo
void	ft_index(t_stack *stack_a);
t_stack	*get_last(t_stack *last);
int		get_max_sorted_list(t_stack *stack, t_stack *start);
t_stack	*ft_max(t_stack *stack);
t_stack	*ft_min(t_stack *stack);
int		ft_sorted(t_stack **stack_a);
int		get_i_max(t_stack *stack, int max);
int		ft_min_steps(t_stack *stack, int index);
int		get_num_on_top(t_stack **stack_a, int index, int min_steps);

int		get_max_sorted(t_stack *first, int trig);
int		loop_stack(t_stack *stack, t_stack *start, int trig);
int		swapable(t_stack *stack);


//       -----  OPERATIONS FUNCTIONS -----       //
void	ft_swap(t_stack **stack, char c);
int		ft_push(t_stack	**st_t, t_stack	**st_r, char c);
int		ft_rotate(t_stack **stack, char c);
int		ft_reverse_rotate(t_stack **stack, char c);
//int		ft_list_len(t_stack **list);

void	ft_ss(t_stack **stack_a, t_stack **stack_b);
// Swap a and b
int		ft_rr(t_stack **stack_a, t_stack **stack_b);
// Rotate a and b
int		ft_rr_ro(t_stack **stack);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
// Reverse Rotate a and b


//       -----  ALGORYTHME FUNCTIONS -----       //
void	ft_algo(t_stack **stack_a, t_stack **stack_b);
void	ft_algo_2(t_stack **stack);
void	ft_algo_3(t_stack **stack);
void	ft_algo_4(t_stack **stack_a, t_stack **stack_b);
void	ft_algo_5(t_stack **stack_a, t_stack **stack_b);
void	ft_algo_big(t_stack **stack_a, t_stack **stack_b);


#endif
