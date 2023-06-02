/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:16:35 by hrobin            #+#    #+#             */
/*   Updated: 2023/05/30 16:29:33 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_error(char *str)
{
	if (str)
		write (1, str, ft_strlen(str));
}

int	clear(t_philo *philo, int nb)
{
	int	i;

	i = 0;
	while (i++ < nb)
	{
		if (pthread_mutex_destroy(&(philo[i].right_fork)) != 0)
			return (1);
		if (pthread_mutex_destroy(&(philo[i].mutex)) != 0)
			return (2);
	}
	return (0);
}

void	id_dead(t_philo *philo)
{
	if (actual_time() - philo->last_bite >= philo->info->ttd)
		//????
}
