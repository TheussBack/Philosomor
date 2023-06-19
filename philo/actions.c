/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:55:48 by hrobin            #+#    #+#             */
/*   Updated: 2023/06/14 16:12:04 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleeping(t_philo *philo)
{
	philo_print(philo, "is sleeping");
	ft_usleep(philo->info->tts, philo);
}

void	eat(t_philo *philo)
{
	if (forking(philo))
	{
		philo_print(philo, "is eating");
		ft_usleep(philo->info->tte, philo);
		philo->last_bite = actual_time();
		philo->eat_count++;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
	}
}

int	forking(t_philo *philo)
{
	if ((philo->philo_id + 1) % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		philo_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork);
		philo_print(philo, "has taken a fork");
		return (1);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork);
		philo_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		philo_print(philo, "Has taken a fork");
		return (2);
	}
	return (0);
}

void	think(t_philo	*philo)
{
	philo_print(philo, "is thinking");
}
