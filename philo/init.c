/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:37:41 by hrobin            #+#    #+#             */
/*   Updated: 2023/06/21 15:24:11 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutexes_info(t_info *info)
{
	if (pthread_mutex_init(&(info->somebody_dead), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(info->food), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(info->lock), NULL) != 0)
		return (1);
	return (0);
}

int	init_mutexes_philo(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&(philo[i].right_fork), NULL) != 0)
			return (1);
		if (pthread_mutex_init(&(philo[i].mutex), NULL) != 0)
			return (1);
		i++;
	}
	i = -1;
	while (++i < nb_philo)
		philo[(i + 1) % nb_philo].left_fork = &philo[i].right_fork;
	return (0);
}

void	init_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		info->philo[i].is_eating = 0;
		info->philo[i].pos = i;
		info->philo[i].eat_count = 0;
		info->philo[i].info = info;
		info->philo[i].last_bite = actual_time();
		info->philo[i].status = BREATHING;
		i++;
	}
}

int	set_philo(t_info *info, int ac, char **av)
{
	info->d_id = -1;
	info->nb_philo = ft_atoi(av[1]);
	info->ttd = ft_atoi(av[2]);
	info->tte = ft_atoi(av[3]);
	info->tts = ft_atoi(av[4]);
	if (ac == 6)
		info->not = ft_atoi(av[5]);
	else
		info->not = 0;
	if (info->nb_philo > 200 || info->ttd < 0
		|| info->tte < 0 || info->tts < 0 || info->not < 0)
		return (1);
	return (0);
}

t_philo	*init(t_info *info)
{
	int	i ;

	info->philo = malloc(sizeof(t_philo) * info->nb_philo);
	if (!info->nb_philo)
		return (NULL);
	i = -1;
	init_philos(info);
	if (init_mutexes_info(info))
		return (NULL);
	if (init_mutexes_philo(info->philo, info->nb_philo))
		return (NULL);
	do_threads(info);
	monitoring(info);
	i = -1;
	while (++i < info->nb_philo)
	{
		if (pthread_join(info->philo[i].philo_id, NULL) != 0)
			return (NULL);
	}
	return (info->philo);
}
