/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:10:15 by hrobin            #+#    #+#             */
/*   Updated: 2023/05/11 23:31:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checkargs(char **av)
{
	int	i;

	i = 0;
	while (av[i++])
	{
		if (is_digit(av[i]) != 0)
		{
			(printf("error: only digits >:(\n"), exit(EXIT_FAILURE));
		}
	}
	return (0);
}

int	is_digit(char *stack)
{
	int	i;

	i = -1;
	while (stack[i + 1] == '-' || stack[i + 1] == '+')
		i++;
	while (stack[++i])
		if (!(stack[i] >= 48 && stack[i] <= 57))
			return (1);
	printf("%ld\n", ft_atoi(stack));
	if (ft_atoi(stack) > 2147483647
			|| ft_atoi(stack) < -2147483648)
		return (1);
	return (0);
}
