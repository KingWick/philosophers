/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:08:55 by akdjebal          #+#    #+#             */
/*   Updated: 2023/10/07 12:54:44 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	routine_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	if (display_philo(get_time(philo->data), philo->id, 'F', philo->data) == 0)
		return (pthread_mutex_unlock(philo->right), 0);
	pthread_mutex_lock(philo->left);
	if (display_philo(get_time(philo->data), philo->id, 'F', philo->data) == 0)
		return (pthread_mutex_unlock(philo->left),
			pthread_mutex_unlock(philo->right), 0);
	pthread_mutex_lock(&philo->gettime);
	philo->last_meal = get_time2();
	pthread_mutex_unlock(&philo->gettime);
	if (display_philo(get_time(philo->data), philo->id, 'E', philo->data) == 0)
		return (pthread_mutex_unlock(philo->left),
			pthread_mutex_unlock(philo->right), 0);
	pthread_mutex_lock(&philo->data->eat_mutex);
	philo->nb_meal++;
	if (philo->nb_meal == philo->data->count_meal)
		philo->data->finish++;
	pthread_mutex_unlock(&philo->data->eat_mutex);
	if (!ft_usleep(philo, philo->data->time_eat))
		return (pthread_mutex_unlock(philo->left),
			pthread_mutex_unlock(philo->right), 0);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (1);
}

void	mark_philo_dead(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	data->dead = 1;
	pthread_mutex_unlock(&data->death_mutex);
}

int	routine_sleep(t_philo *philo)
{
	if (display_philo(get_time(philo->data), philo->id, 'S', philo->data) == 0)
		return (0);
	if (!ft_usleep(philo, philo->data->time_sleep))
		return (0);
	return (1);
}

void	*check_routine(void *arg)
{
	int		i;
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		i = -1;
		while (++i < philo->data->count_philo)
		{
			update_last_meal(data, i);
			pthread_mutex_lock(&philo->data->eat_mutex);
			if (philo->time > philo->data->time_dead
				|| (data->count_meal > 0 && data->finish == data->count_philo))
			{
				mark_philo_dead(data);
				if (philo->time > philo->data->time_dead)
					display_philo(philo->time, philo->id, 'D', philo->data);
				return (pthread_mutex_unlock(&philo->data->eat_mutex), NULL);
			}
			pthread_mutex_unlock(&philo->data->eat_mutex);
		}
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo			*data;
	pthread_mutex_t	*tmp;

	data = (t_philo *)arg;
	if (data->id % 2 == 0)
	{
		tmp = data->left;
		data->left = data->right;
		data->right = tmp;
		if (ft_usleep(data, 50) == 0)
			return (NULL);
	}
	while (1)
	{
		if (routine_eat(data) == 0)
			break ;
		if (routine_sleep(data) == 0)
			break ;
		if (display_philo(get_time(data->data), data->id, 'T', data->data) == 0)
			break ;
	}
	return (NULL);
}
