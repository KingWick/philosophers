/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:25:02 by akdjebal          #+#    #+#             */
/*   Updated: 2023/10/07 14:21:09 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_philo(long time, int philo_id, char event, t_data *data)
{
	if (check_death(data) == 0 && event != 'D')
		return (0);
	pthread_mutex_lock(&data->write);
	if (event == 'E')
		printf("%ld ms %d is eating\n", time, philo_id);
	else if (event == 'F')
		printf("%ld ms %d has taken a fork\n", time, philo_id);
	else if (event == 'S')
		printf("%ld ms %d is sleeping\n", time, philo_id);
	else if (event == 'T')
		printf("%ld ms %d is thinking\n", time, philo_id);
	else if (event == 'D')
	{
		return (printf("%ld ms %d died\n", time, philo_id),
			pthread_mutex_unlock(&data->write), 0);
	}
	pthread_mutex_unlock(&data->write);
	return (1);
}

int	main(int ac, char **av)
{
	static t_data	data = {0};

	if (ac == 5 || ac == 6)
	{
		if (check_args(ac, av) == 0)
		{
			printf("Wrong arguments");
			return (0);
		}
		if (ft_atoi(av[1]) == 1)
		{
			printf("0 1 has taken a fork\n");
			usleep(ft_atoi(av[2]) * 1000);
			printf("%d 1 has died\n", ft_atoi(av[2]));
			return (0);
		}
		init_philo_data(&data, av);
		init_philo_tab(&data);
		ft_free_all(&data);
	}
	else
		printf("Wrong arguments");
	return (0);
}
