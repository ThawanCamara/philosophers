/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 05:39:07 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/21 11:55:28 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Creates threads to simulate philosophers. As many threads as philosophers.
void	ft_create_threads(t_sim *sim)
{
	unsigned int	i;

	i = 0;
	while (i < sim->total_philos)
	{
		pthread_create(&sim->philo[i].thread, NULL, ft_philo_sim,
			&sim->philo[i]);
		i++;
	}
}

// Joins back all executing threads, freeing resources used.
void	ft_join_threads(t_sim *sim)
{
	unsigned int	i;

	i = 0;
	while (i < sim->total_philos)
	{
		pthread_join(sim->philo[i].thread, NULL);
		i++;
	}
}
