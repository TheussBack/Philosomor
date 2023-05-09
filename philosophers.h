/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:38:44 by hrobin            #+#    #+#             */
/*   Updated: 2023/05/09 13:20:50 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

# define	BREATHING 0
# define	LIFELESS -1
# define	DREAMING 1
# define	CHEWING 2

typedef struct s_philo
{
	pthread_t	philo_id;
	int	pos;
	int	is_eating;
	int	limit;
	int	last_bite;
	int	eat_count;
	int	status;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
	struct s_info *info;
	pthread_mutex_t	mutex;
}					t_philo;

typedef struct	s_info
{
	int	nb_philo;
	int	ttd;
	int	tte;
	int	tts;
	int	must_eat;
	int	d_id;
	t_philo	*philo;
	pthread_mutex_t	somebody_dead;
	pthread_mutex_t	food;
	pthread_mutex_t	lock;
}			t_info;

//time
void	ft_usleep(long int time_in_ms);
long int	actual_time(void);

//parse
int	checkargs(char **av);
int	is_digit(char *stack);

//init
t_philo *init(t_info *info, int ac, char **av);
void	init_philos(t_info *info);
void	set_philo(t_info *info, int ac, char **av);
int	init_mutexes_philo(t_philo *philo, int nb_philo);
int	init_mutexes_info(t_info *info);

//error
void	exit_error(char *str);
int	clear(t_philo *philo, int nb);

//utils
ssize_t	ft_strlen(char *str);
int	ft_atoi(char *str);

//
void	do_threads(t_info *info);
void	*routine();


#endif
