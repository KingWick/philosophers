/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:51:31 by rr                #+#    #+#             */
/*   Updated: 2023/10/05 15:32:09 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_mutex(t_data *data)
{
    data->fork = ft_calloc(data->count_philo, sizeof(pthread_mutex_t));
    if (!data->fork)
        free(data->philo);
    pthread_mutex_init(&data->write_mutex, NULL);
    pthread_mutex_init(&data->death_mutex, NULL);
    pthread_mutex_init(&data->eat_mutex, NULL);
}

void init_forks(t_data *data)
{
	int i;
	int left;
	
	i = 0;
	while (i < data->count_philo)
	{
		if (i == 0)
			left = data->count_philo - 1;
		else
			left = i - 1;
		data->philo[i].right = &data->fork[i];
		data->philo[i].left = &data->fork[left];
		i++;
	}
}

t_data *init_philo_data(t_data *data, char **av)
{
    int i;
    
    i = 0;
    gettimeofday(&data->start_time, NULL);
    data->time = (data->start_time.tv_sec * 1000) + (data->start_time.tv_usec / 1000);
    data->count_philo = ft_atoi(av[1]);
    data->time_dead = ft_atoi(av[2]);
    data->time_eat = ft_atoi(av[3]);
    data->time_sleep = ft_atoi(av[4]);
    data->count_meal = ft_atoi(av[5]);
    data->philo = ft_calloc(data->count_philo, sizeof(t_philo));
    if (!data->philo)
        return (0);
    init_mutex(data);
    while (i < data->count_philo)
    {
        data->philo[i].last_meal = actual_time2();
        pthread_mutex_init(&data->fork[i], NULL);
        pthread_mutex_init(&data->philo[i].gettime, NULL);
        data->philo[i].data = data;
		data->philo[i].id = i + 1;
        i++;
    }
    init_forks(data);
	return(data);
}

void	init_philo_tab(t_data *data)
{
	int i;
	int nb;
	
	i = 0;
	nb = data->count_philo - 1;
	while (i <= nb)
	{
		pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]);
		i++;
	}
	pthread_create(&data, NULL, check_routine, &data->philo[0]);
	pthread_join(data->check_death, NULL);
	i = 0;
	while (i <= nb)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

