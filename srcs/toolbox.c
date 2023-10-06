/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rr <rr@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:12:59 by akdjebal          #+#    #+#             */
/*   Updated: 2023/10/06 23:32:55 by rr               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	if (data->dead == 1)
		return (pthread_mutex_unlock(&data->death_mutex), 0);
	pthread_mutex_unlock(&data->death_mutex);
	return (1);
}

long long	actual_time(t_data *data)
{
	struct timeval	time;
	long long		actual_time;

	gettimeofday(&time, NULL);
	actual_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (actual_time - data->time);
}

long long	actual_time2(void)
{
	struct timeval	time;
	long long		actual_time;

	gettimeofday(&time, NULL);
	actual_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (actual_time);
}

long long	get_time2(void)
{
	struct timeval	time;
	long long		actual_time;

	gettimeofday(&time, NULL);
	actual_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (actual_time);
}

long long	get_time(t_data *data)
{
	struct timeval	time;
	long long		actual_time;

	gettimeofday(&time, NULL);
	actual_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (actual_time - data->time);
}
