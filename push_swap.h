/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:09:12 by thi-phng          #+#    #+#             */
/*   Updated: 2021/12/01 16:17:49 by thi-phng         ###   ########.fr       */
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
	int				stay;
	int				nb_team;
	int				gap;
	int				size;
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

// Free functions
void	ft_free_1st(t_stack **st, int n);
void	ft_free(t_stack **st_a, t_stack **st_b, int n);
// void    ft_error(t_stack **st_a, t_stack **st_b, int n);
// void	ft_error()
// int		ft_check_double(t_stack **list_a);


// LISTE CHAINEE starts here //
int		ft_new_element(t_stack	**stack, int n);
int		ft_size_stack(t_stack **stack);
void	ft_display_stack(t_stack *stack);
int		ft_doublons(t_stack *stack);
void	ft_init_elem(t_stack *new);

// tools in algo

// t_stack	*get_last(t_stack *last);

void	ft_init(t_env *f);
void	show_stay(t_stack **st);


//       -----  OPERATIONS FUNCTIONS -----       //
void	ft_swap(t_stack **stack, char c);
int		ft_push(t_stack	**st_t, t_stack	**st_r, char c);
int		ft_rotate(t_stack **stack, char c);
int		ft_reverse_rotate(t_stack **stack, char c);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
// Swap a and b
int		ft_rr(t_stack **stack_a, t_stack **stack_b);
// Rotate a and b
int		ft_rr_ro(t_stack **stack);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
// Reverse Rotate a and b


// big_algo_1
int		ft_sorted(t_stack **stack_a);
void	ft_index(t_stack *stack_a);
void	sorter(t_stack **st_a, t_stack **st_b);
// void	init_stay(t_stack **st);
void	get_stay(t_stack **st, t_stack *first);
void	init_max_sorted(t_stack **first);
int		get_max_nb_team(t_stack **stack);
t_stack	*get_head_stay(t_stack **st_a);
t_stack	*get_p_number(t_stack **st_a, int n);
int		get_num_on_top(t_stack **stack_a, int index, int min_steps, char c);
int		ft_min_steps(t_stack *stack, int index);
int		done_push_in_b(t_stack *st);


// big_algo_2
t_stack	*ft_max(t_stack *stack);
t_stack	*ft_min(t_stack *stack);
void	set_gap_b(t_stack **st_a, t_stack **st_b);
int		swapable(t_stack *stack);
t_stack	*ft_compare_b(t_stack **st_b);
void	ft_push_b_back(t_stack **tmp_b, t_stack **tmp_a, t_stack *min_b);

//       -----  ALGORYTHME FUNCTIONS -----       //
void	ft_algo(t_stack **stack_a, t_stack **stack_b);
void	ft_algo_2(t_stack **stack);
void	ft_algo_3(t_stack **stack);
void	ft_algo_4(t_stack **stack_a, t_stack **stack_b);
void	ft_algo_5(t_stack **stack_a, t_stack **stack_b);
void	ft_algo_big(t_stack **stack_a, t_stack **stack_b);


#endif
