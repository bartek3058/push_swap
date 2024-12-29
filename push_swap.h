/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:22:55 by brogalsk          #+#    #+#             */
/*   Updated: 2024/12/27 10:01:54 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

void	ft_check_args(int argc, char **argv);
void	ft_free(char **args);
void	utils2(char **args, int i, int argc, long temp);
void	index_stack(t_list **stack);
void	ft_listadd_front(t_list **stack, t_list *new);
void	ft_listadd_back(t_list **stack, t_list *new);
void	initstack(t_list **stack, int argc, char **argv);
void	free_stack(t_list **stack);
void	simple_sort(t_list **stack_a, t_list **stack_b);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	ft_error(void);
void	utils(t_list **stack_a, t_list *head, int min);
int		ft_isnum(char *s);
int		ft_double(int temp, char **s, int i);
int		ft_listsize(t_list *head);
int		is_sorted(t_list **stack);
int		swap(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		push(t_list **stack_to, t_list **stack_from);
int		rrr(t_list **stack_a, t_list **stack_b);
int		rrb(t_list **stack_b);
int		rra(t_list **stack_a);
int		reverserotate(t_list **stack);
int		rr(t_list **stack_a, t_list **stack_b);
int		rb(t_list **stack_b);
int		ra(t_list **stack_a);
int		rotate(t_list **stack);
int		pb(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		get_min_index(t_list **stack, int val);
int		get_distance(t_list **stack, int index);
int		get_max_bits(t_list **stack);
t_list	*get_next_min(t_list **stack);
t_list	*ft_listlast(t_list *head);
t_list	*ft_listnew(int value);

#endif
