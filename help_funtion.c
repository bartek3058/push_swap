/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funtion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:23:04 by brogalsk          #+#    #+#             */
/*   Updated: 2024/12/27 09:34:13 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push (stack_a, stack_b) == -1)
		return (-1);
	ft_putstr_fd("pa\n", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push (stack_b, stack_a) == -1)
		return (-1);
	ft_putstr_fd("pb\n", 1);
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_listsize (*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_listlast(head);
	*stack = head -> next;
	head -> next = NULL;
	tail -> next = head;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate (stack_a) == -1)
		return (-1);
	ft_putstr_fd("ra\n", 1);
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate (stack_b) == -1)
		return (-1);
	ft_putstr_fd("rb\n", 1);
	return (0);
}
