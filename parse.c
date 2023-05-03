/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:10:15 by hrobin            #+#    #+#             */
/*   Updated: 2023/05/03 17:43:27 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkargs(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (is_digit(av[1]) == 1)
			return (exit_error("error: while parsing arg"));
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
		if (!(stack[i] >= '0' && stack[i] <= '9'))
			return (1);
	if (i >= 10 && (ft_atoi(stack) > 2147483647
			|| ft_atoi(stack) < -2147483648))
		return (1);
	return (0);
}
