/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:00:31 by hrobin            #+#    #+#             */
/*   Updated: 2023/05/11 23:36:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atoi(char *str)
{
	long res;
	int	s;
	int i;

	res = 0;
	s = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] < '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * s);
}

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = -1;
	while (str[i])
		++i;
	return(i);
}
