/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:46:28 by rr                #+#    #+#             */
/*   Updated: 2023/10/07 13:18:22 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_data *data)
{
	ft_destroy_mutex(data);
	free(data->philo);
	free(data->fork);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	signe;

	i = 0;
	result = 0;
	signe = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
	}
	return (result * signe);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	valid_atoi(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	if (valid_atoi(av[1]) && valid_atoi(av[2]) && valid_atoi(av[3])
		&& valid_atoi(av[4]))
	{
		if (ft_atoi(av[1]) == 0)
			return (0);
		if (ac == 6)
		{
			if (valid_atoi(av[5]))
				return (1);
			puts("ici");
		}
		else
			return (1);
	}
	return (0);
}
