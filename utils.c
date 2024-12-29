/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:08:45 by brogalsk          #+#    #+#             */
/*   Updated: 2024/12/28 13:07:46 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	utils(t_list **stack_a, t_list *head, int min)
{
	if (head -> next -> index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	utils2(char **args, int i, int argc, long temp)
{
	while (args[i])
	{
		temp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
		{
			if (argc == 2)
				ft_free(args);
			ft_error();
		}
		if (ft_double(temp, args, i))
		{
			if (argc == 2)
				ft_free(args);
			ft_error();
		}
		if (temp < -2147483648 || temp > 2147483647)
		{
			if (argc == 2)
				ft_free(args);
			ft_error();
		}
		i++;
	}
}
