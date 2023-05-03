/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:38:44 by hrobin            #+#    #+#             */
/*   Updated: 2023/05/03 18:18:25 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHES_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
	int	pos;
	int	is_eating;
	int	limit;
	int	last_eat;
	int	eat_count;
	int	right_fork;
	int	left_fork;
	struct s_info *info;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;
}					t_philo;

typedef struct	s_info
{
	int	nb_philo;
	int	ttd;
	int	tte;
	int	tts;
	int	must_eat;
	int	thread_id;
	t_philo	*philos;
	pthread_mutex_t	*somebody_dead;
}			t_info;

//time
void	ft_usleep(long int time_in_ms);
long int	actual_time(void);

//parse
int	checkargs(char **av);
int	is_digit(char *stack);

//init
int	init(t_info *info, int ac, char **av);
void	init_philos(t_info *info);

//error
void	exit_error(char *str);

#endif
