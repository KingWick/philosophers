/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:08:55 by akdjebal          #+#    #+#             */
/*   Updated: 2023/10/05 15:34:23 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *check_routine(void *arg)
{
	
}

void *routine(void *arg)
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
		if (ft_eat(data) == 0)
			break ;
		if (ft_sleep(data) == 0)
			break ;
		if (state_change(get_time(data->data), data->id, 'T', data->data) == 0)
			break ;
	}
	return (NULL);
}


