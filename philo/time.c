/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:10:05 by hrobin            #+#    #+#             */
/*   Updated: 2023/06/23 15:18:43 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long int time_in_ms, t_philo *philo)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time_in_ms && is_dead(philo))
		usleep(time_in_ms / 10);
}

long int	actual_time(void)
{
	static long		init_time = 0;
	long int		time;
	struct timeval	tv;

	if (init_time == 0)
	{
		gettimeofday(&tv, NULL);
		init_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		time = 0;
	}
	else
	{
		gettimeofday(&tv, NULL);
		time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - init_time;
	}
	return (time);
}
