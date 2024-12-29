/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:22:26 by brogalsk          #+#    #+#             */
/*   Updated: 2024/12/28 13:07:23 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	while (i >= 0)
		free(s[i--]);
	free(s);
}

int	ft_double(int temp, char **s, int i)
{
	i++;
	while (s[i])
	{
		if (ft_atoi(s[i]) == temp)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	temp;
	char	**args;

	temp = 0;
	i = 0;
	if (argc == 2)
		args = ft_split (argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	utils2(args, i, argc, temp);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_args (argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	initstack(stack_a, argc, argv);
	if (is_sorted(stack_a) == 1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
