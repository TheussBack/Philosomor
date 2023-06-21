/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:00:31 by hrobin            #+#    #+#             */
/*   Updated: 2023/06/21 15:12:43 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atoi(char *str)
{
	long res;
	int	s;
	int i;

	res = 0;
	s = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * s);
}

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = -1;
	while (str[i])
		++i;
	return(i);
}

int	one_philo(t_philo *philo)
{
	printf("%ld 1 has taken a fork\n", actual_time());
	usleep(philo->info->ttd * 1000);
	creve(philo);
	return (0);
}

void	philo_print(t_philo *philo, const char *text)
{
	pthread_mutex_lock(&(philo->info->lock));
	if (philo->status == LIFELESS || philo->info->d_id != -1)
	{
		pthread_mutex_unlock(&(philo->info->lock));
		return ;
	}
	printf("%lu %d %s\n", actual_time(), philo->pos + 1, text);
	pthread_mutex_unlock(&(philo->info->lock));
}

void	monitoring(t_info *info)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < info->nb_philo)
		{
			if (is_dead(&info->philo[i]))
				i++;
			else return ;
		}
		usleep(100);
	}
}
