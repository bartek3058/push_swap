/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:21:55 by brogalsk          #+#    #+#             */
/*   Updated: 2024/12/27 09:30:43 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list		*head;
	t_list		*next;
	int			tmp_val;
	int			tmp_index;

	if (ft_listsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_putstr_fd("Error during swapping!", 1);
	tmp_val = head->value;
	tmp_index = head ->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap (stack_a) == -1)
		return (-1);
	ft_putstr_fd("sa\n", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap (stack_b) == -1)
		return (-1);
	ft_putstr_fd("sb\n", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if ((ft_listsize(*stack_a) < 2) || (ft_listsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
	return (0);
}

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_listsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from -> next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to -> next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp -> next = head_to;
		*stack_to = tmp;
	}
	return (0);
}
