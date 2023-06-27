/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutexes_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 04:41:56 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 14:37:13 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Initializes every mutex in use by the project.
void	ft_init_mutexes(t_sim *sim)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < sim->total_philos)
	{
		pthread_mutex_init(&sim->mutex_forks[i], NULL);
		j = 0;
		while (j < MAX_PHILO_MUTEXES)
			pthread_mutex_init(&sim->philo[i].mutex[j++], NULL);
		i++;
	}
	j = 0;
	while (j < MAX_SIM_MUTEXES)
		pthread_mutex_init(&sim->mutex[j++], NULL);
}

// Destroy every used mutex, thus freeing its resources.
void	ft_destroy_mutexes(t_sim *sim)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < sim->total_philos)
	{
		pthread_mutex_destroy(&sim->mutex_forks[i]);
		j = 0;
		while (j < MAX_PHILO_MUTEXES)
			pthread_mutex_destroy(&sim->philo[i].mutex[j++]);
		i++;
	}
	j = 0;
	while (j < MAX_SIM_MUTEXES)
		pthread_mutex_destroy(&sim->mutex[j++]);
}
