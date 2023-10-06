/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rr <rr@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:03:40 by akdjebal          #+#    #+#             */
/*   Updated: 2023/10/06 17:20:41 by rr               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>

typedef struct	s_philo
{
	pthread_mutex_t *left;
	pthread_mutex_t *right;
	pthread_mutex_t gettime;
	pthread_t		thread;
	struct s_data	*data;
	int				id;
	int 			nb_meal;
	long			time;
	long long 		last_meal;
}					t_philo;

typedef struct s_data
{
	pthread_mutex_t		*fork;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		write;
	pthread_mutex_t		eat_mutex;
	struct timeval 		start_time;
	long 				time;
	int 				finish;
	int					dead;
	int					count_philo;
	int					count_meal;
	int					time_dead;
	int					time_eat;
	int					time_sleep;
	t_philo				*philo;
	pthread_t			check_death;
	
}				t_data;

//---------------Event-------------------//

int 	display_philo_status(long time, int philo_id, char event, t_data *data);
int 	routine_eat(t_philo *philo);
int		routine_sleep(t_philo *philo);

//---------Check and parsing--------//

int		check_args(int ac, char **av);
int 	valid_atoi(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

//---------Initialisation----------//

t_data 	*init_philo_data(t_data *data, char **av);
void	init_philo_tab(t_data *data);
void 	init_mutex(t_data *data);
void 	init_forks(t_data *data);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

//-----------Time----------------//
int			ft_usleep(t_philo *data, unsigned long int time);
long long	get_time(t_data *data);
long long	get_time2(void);
long long	actual_time(t_data *data);
long long	actual_time2(void);

//----------Check routine and death-------//
void 		*routine(void *arg);
void 		*check_routine(void *arg);
void		mark_philo_dead(t_data *data);
void		update_last_meal(t_data *data, int i);
int			check_death(t_data *data);

//----------Free and destroy everything-------//
void	ft_destroy_mutex(t_data *arg);
void	ft_free_all(t_data *data);

#endif