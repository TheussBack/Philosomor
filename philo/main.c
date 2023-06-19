/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:25:14 by hrobin            #+#    #+#             */
/*   Updated: 2023/06/19 12:06:24 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	if (philo->info->nb_philo == 1)
	{
		one_philo(philo);
		return (NULL);
	}
	if (philo->pos % 2 == 0)
		usleep(philo->info->tte * 1000);
	// printf("%i\n", philo->pos);
	while (is_dead(philo))
	{
		eat(philo);
		sleeping(philo);
		think(philo);
	}
	return (0);
}

void	do_threads(t_info *info)
{
	int	i;

	i = -1;
	while ((++i < info->nb_philo) && (&info->philo[i]))
	{
		// if (i % 2 == 0)
			if(pthread_create(&(info->philo[i].philo_id), NULL, &routine,
			(void *)&info->philo[i]) != 0)
				return ;
	}
	// usleep(10);
	// i = -1;
	// while ((++i < info->nb_philo) && (&info->philo[i]))
	// {
	// 	if (i % 2 != 0)
	// 		if(pthread_create(&(info->philo[i].philo_id), NULL, &routine,
	// 		(void *)&info->philo[i]) != 0)
	// 			return ;
	// }
}

int	main(int ac, char **av)
{
	t_info	info;
	int i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (printf("error: wrong nb of arguments\n"), 1);
	checkargs(av);
	if ((set_philo(&info, ac, av)))
		(printf("wrong args\n"), exit(EXIT_FAILURE));
	// write (1,"set philo check\n", 16);
	info.philo = init(&info);
	// write (1, "init check\n", 11);
	if (info.philo == NULL)
		exit_error("error: fatal\n");
	clear(info.philo, info.nb_philo);
	free(info.philo);
	// write (1,"reached the end\n", 16);
	// return (0);
}