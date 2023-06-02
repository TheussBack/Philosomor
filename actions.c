/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:55:48 by hrobin            #+#    #+#             */
/*   Updated: 2023/05/30 16:23:38 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleep(t_philo *philo)
{
	print(philo, "is_sleeping");
	ft_usleep(philo->info->tts, philo);
}

int	eat(t_philo *philo)
{
	int	i;

	i = 0;
	while (i == 0 && is_dead(philo))
	{
		if (forking(philo))
		{
			print(philo, "is_eating");
			ft_usleep(philo->info->tte, philo);
			philo->last_bite = acual_time();
			philo->eat_count++;
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(&philo->right_fork);
			i++;
		}
	}
}

int	forking(t_philo *philo)
{
	if ((philo->philo_id + 1) % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork);
		print(philo, "Has taken a fork");
		retrun (1);
	}
	else
		pthread_mutex_lock(&philo->right_fork);
		print(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print(philo, "Has taken a fork");
		retrun (2);
	return (0);
}

void	think(t_philo	*philo)
{
	print(philo, "is_thinking");
}
