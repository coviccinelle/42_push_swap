/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:09:12 by thi-phng          #+#    #+#             */
/*   Updated: 2021/10/28 17:57:16 by thi-phng         ###   ########.fr       */
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
	void			*next;
}				t_stack;



// UTILS //
//
int	find_me(char c, const char *str);
int	ft_int_exist(char *str);
int	ft_all_blank(char *str);
int	ft_atoi_1(char *str);
int	ft_strlen(char *str);
int	ft_invalid_char(char *str);
int	ft_min(int a, int b);
int	ft_max(int a, int b);
int	ft_2nb_stick(char *str);

// PARSING PARTs //
int	ft_parsing_1(char *str);
int	ft_parsing_multi_2(int ac, char **av);

void	ft_free_ck(t_stack **list_a);
int		ft_check_double(t_stack **list_a);



// LISTE CHAINEE starts here //
//
//
void	ft_new_element(t_stack	**Stack, int n);
int		ft_size_stack(t_stack **Stack);
int		ft_display_stack(t_stack *Stack);



//       -----  OPERATIONS FUNCTIONS -----       //
//
//
void	ft_swap(t_stack *Stack, char c);
int		ft_push(t_stack	*st_t, t_stack	*st_r, char c);
void		ft_rotate_i(t_stack *Stack, char c);
int		ft_reverse(t_stack **list, char c);
int		ft_list_len(t_stack **list);

void	ft_ss(t_stack **list_a, t_stack **list_b);
void	ft_rr(t_stack **list_a, t_stack **list_b);
void	ft_rrr(t_stack **list_a, t_stack **list_b);
void	ft_r_rr(t_stack **list);


#endif
