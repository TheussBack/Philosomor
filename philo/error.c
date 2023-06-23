/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:16:35 by hrobin            #+#    #+#             */
/*   Updated: 2023/06/23 15:14:44 by hrobin           ###   ########.fr       */
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
	while (i < nb)
	{
		if (pthread_mutex_destroy((philo[i].left_fork)) != 0)
			return (1);
		if (pthread_mutex_destroy(&(philo[i].mutex)) != 0)
			return (2);
		i++;
	}
	return (0);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex));
	if (actual_time() - philo->last_bite >= (long int)philo->info->ttd)
	{
		pthread_mutex_unlock(&(philo->mutex));
		pthread_mutex_lock(&(philo->info->lock));
		if (philo->info->d_id != -1)
			return (pthread_mutex_unlock(&(philo->info->lock)), 0);
		pthread_mutex_unlock(&(philo->info->lock));
		creve(philo);
		return (0);
	}
	pthread_mutex_unlock(&(philo->mutex));
	pthread_mutex_lock(&(philo->info->lock));
	if (philo->info->d_id != -1)
		return (pthread_mutex_unlock(&(philo->info->lock)), 0);
	pthread_mutex_unlock(&(philo->info->lock));
	pthread_mutex_lock(&(philo->mutex));
	if (philo->info->not != 0 && philo->eat_count >= philo->info->not)
		return (pthread_mutex_unlock(&(philo->mutex)), 0);
	pthread_mutex_unlock(&(philo->mutex));
	return (1);
}

void	creve(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->lock));
	if (philo->info->d_id != -1)
	{
		pthread_mutex_unlock(&(philo->info->lock));
		return ;
	}
	printf("%lu %d %s\n", actual_time(), philo->pos + 1, "died");
	philo->info->d_id = philo->pos + 1;
	philo->status = LIFELESS;
	pthread_mutex_unlock(&(philo->info->lock));
}
