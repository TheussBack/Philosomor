/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:38:44 by hrobin            #+#    #+#             */
/*   Updated: 2023/06/23 15:21:48 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# define BREATHING 0
# define LIFELESS -1
# define DREAMING 1
# define CHEWING 2

typedef struct s_philo
{
	pthread_t		philo_id;
	int				pos;
	int				is_eating;
	int				limit;
	int				last_bite;
	int				eat_count;
	int				status;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
	struct s_info	*info;
	pthread_mutex_t	mutex;
}					t_philo;

typedef struct s_info
{
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				not ;
	int				d_id;
	t_philo			*philo;
	pthread_mutex_t	somebody_dead;
	pthread_mutex_t	food;
	pthread_mutex_t	lock;
}					t_info;

//time
void				ft_usleep(long int time_in_ms, t_philo *philo);
long int			actual_time(void);

//parse
int					checkargs(char **av);
int					is_digit(char *stack);

//init
int					init_mutexes_info(t_info *info);
int					init_mutexes_philo(t_philo *philo, int nb_philo);
void				init_philos(t_info *info);
int					set_philo(t_info *info, int ac, char **av);
t_philo				*init(t_info *info);

//error
void				exit_error(char *str);
int					clear(t_philo *philo, int nb);
int					is_dead(t_philo *philo);
void				creve(t_philo *philo);

//utils
ssize_t				ft_strlen(char *str);
long				ft_atoi(char *str);
int					one_philo(t_philo *philo);
void				philo_print(t_philo *philo, const char *text);
void				monitoring(t_info *info);

//actions
void				sleeping(t_philo *philo);
void				eat(t_philo *philo);
int					forking(t_philo *philo);
void				think(t_philo *philo);

//
void				do_threads(t_info *info);
void				*routine(void *philo);

#endif
