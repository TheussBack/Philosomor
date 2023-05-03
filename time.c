/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:10:05 by hrobin            #+#    #+#             */
/*   Updated: 2023/05/03 17:45:31 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long int time_in_ms)
{
	long int	start_time = 0;

	start_time = actual_time();
	while((actual_time()-start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

long int	actual_time(void)
{
	long int	time = 0;
	struct timeval	curent_time;
	if (gettimeofday(&curent_time, NULL) == -1)
		exit_error("error: gettimeofday -1\n");
	time = (curent_time.tv_sec * 1000) + (curent_time.tv_usec / 1000);
	return (time);
}
