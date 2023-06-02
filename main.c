/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:25:14 by hrobin            #+#    #+#             */
/*   Updated: 2023/05/30 16:32:50 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *philo)
{
	//if (nb_philo == 1)
	while (is_dead(philo))
	{
		if (is_dead(philo))
			return (philo);
		eat(philo);
		if (is_dead(philo))
			return (philo);
		sleep(philo);
		if (is_dead(philo))
			return (philo);
		think(philo);
	}
}

void	do_threads(t_info *info)
{
	int	i;

	i = -1;
	while ((++i < info->nb_philo) && (&info->philo[i]))
	{
		if (i % 2 == 0)
			if(pthread_create(&(info->philo[i].philo_id), NULL, &routine, NULL))
			//manque certainement les arguents de la routine mais ??
				return ;
	}
	i = -1;
	while ((++i < info->nb_philo) && (&info->philo[i]))
	{
		if (i % 2 != 0)
			if(pthread_create(&(info->philo[i].philo_id), NULL, &routine, NULL))
				return ;
	}
	printf("%d\n", i);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac < 5 || ac > 6)
		return (printf("error: wrong nb of arguments\n"), 1);
	checkargs(av);
	if ((set_philo(&info, ac, av)))
		(printf("wrong args\n"), exit(EXIT_FAILURE));
	write (1,"set philo check\n", 16);
	info.philo = init(&info);
	write (1, "init check\n", 11);
	if (info.philo == NULL)
		exit_error("error: fatal\n");
	//clear();
	return (0);
}
