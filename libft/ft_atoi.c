/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:00:21 by brogalsk          #+#    #+#             */
/*   Updated: 2024/12/27 16:43:55 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	int		i;
	int		c;
	long	d;

	i = 0;
	c = 1;
	d = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			c = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		d = d * 10 + (nptr[i] - '0');
		i++;
	}
	return (c * d);
}
/*int main()
{
	int c;
	c = atoi("\t \n- -123");
	printf("%d\n", c);
	printf("%d\n", ft_atoi("\t  \n- -123"));
	return (0);
}*/
