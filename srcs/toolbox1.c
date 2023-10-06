/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rr <rr@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:30:48 by rr                #+#    #+#             */
/*   Updated: 2023/10/06 23:34:15 by rr               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_last_meal(t_data *data, int i)
{
	pthread_mutex_lock(&data->philo[i].gettime);
	data->philo[i].time = get_time2() - data->philo[i].last_meal;
	pthread_mutex_unlock(&data->philo[i].gettime);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n > 0)
	{
		--n;
		str[n] = '\0';
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}

void	ft_destroy_mutex(t_data *arg)
{
	int	i;

	i = 0;
	while (i < arg->count_philo - 1)
	{
		pthread_mutex_destroy(&arg->fork[i]);
		pthread_mutex_destroy(&arg->philo[i].gettime);
		i++;
	}
	pthread_mutex_destroy(&arg->death_mutex);
	pthread_mutex_destroy(&arg->write);
	pthread_mutex_destroy(&arg->eat_mutex);
}
int	ft_usleep(t_philo *data, unsigned long int time)
{
	unsigned long int	start;

	start = get_time(data->data);
	while (get_time(data->data) - start < time)
	{
		usleep(100);
		if (check_death(data->data) == 0)
			return (0);
	}
	return (1);
}

