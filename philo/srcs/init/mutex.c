/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:15:18 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/20 14:12:33 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static bool	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_mutex_init(&data->mtx_forks[i], NULL))
			return (false);
		i++;
	}
	if (pthread_mutex_init(&data->mtx_exit, NULL))
		return (false);
	if (pthread_mutex_init(&data->mtx_printf, NULL))
		return (false);
	return (true);
}

bool	init_mutex_and_check(t_data *data)
{
	if (!init_mutex(data))
	{
		print_error(ERR_MTX_INIT);
		return (false);
	}
	return (true);
}

// void	init_mutex(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->num_of_philo)
// 	{
// 		if (pthread_mutex_init(&data->mtx_forks[i], NULL))
// 		{
// 			print_error(ERR_MTX_INIT);
// 		}
// 		i++;
// 	}
// 	if (pthread_mutex_init(&data->mtx_exit, NULL))
// 	{
// 			print_error(ERR_MTX_INIT);
// 	}
// 	if (pthread_mutex_init(&data->mtx_printf, NULL))
// 	{
// 		print_error(ERR_MTX_INIT);
// 	}
// }

// void	init_mutex(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->num_of_philo)
// 	{
// 		pthread_mutex_init(&data->mtx_forks[i], NULL);
// 		i++;
// 	}
// 	pthread_mutex_init(&data->mtx_exit, NULL);
// 	pthread_mutex_init(&data->mtx_printf, NULL);
// }
