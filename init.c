/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:37:41 by hrobin            #+#    #+#             */
/*   Updated: 2023/05/03 15:43:59 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutexes(t_info *info)
{
	//tg
}

void	init_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		info->philos[i].is_eating = 0;
		info->philos[i].pos = i;
		info->philos[i].right_fork = (i + 1) % info->nb_philo;
		info->philos[i].left_fork = i;
		info->philos[i].eat_count = 0;
		info->philos[i].info = info;
		pthread_mutex_init(&info->philos[i].mutex, NULL); 
		pthread_mutex_init(&info->philos[i].eat_m, NULL);
		pthread_mutex_lock(&info->philos[i].eat_m);
		i++;
	}
}

int	init(t_info *info, int ac, char **av)
{
	info->nb_philo = ft_atoi(av[1]);
	info->ttd = ft_atoi(av[2]);
	info->tte = ft_atoi(av[3]);
	info->tts =ft_atoi(av[4]);
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = 0;
	if (info->nb_philo < 2 || info->nb_philo > 200 || info->ttd < 0
		|| info->tte < 0 || info->tts < 0 || info->must_eat < 0)
		return (1);
	init_philos(info);
	return(init_mutexes(info));

}
