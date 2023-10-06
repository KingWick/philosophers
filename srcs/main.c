/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rr <rr@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:25:02 by akdjebal          #+#    #+#             */
/*   Updated: 2023/10/06 17:32:21 by rr               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	static t_data data = {0};
	
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
		init_philo_data(&data,av);
		init_philo_tab(&data);
		ft_free_all(&data);
	}
	else
		printf("Wrong arguments");
	return (0);
}
