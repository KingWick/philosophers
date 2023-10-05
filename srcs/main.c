/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:25:02 by akdjebal          #+#    #+#             */
/*   Updated: 2023/10/05 12:40:26 by akdjebal         ###   ########.fr       */
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
		init_philo_data(&data,av);
	}
	else
		printf("Wrong arguments");
	return (0);
}
