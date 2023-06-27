/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:00:37 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 14:47:33 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Initializes the simulation's struct with information from the terminal.
void	ft_init_sim(t_sim *sim, char *argv[])
{
	sim->sim_running = 0;
	sim->total_philos = ft_atou(argv[1]);
	sim->max_time[DIE] = ft_atou(argv[2]) * 1000;
	sim->max_time[EAT] = ft_atou(argv[3]) * 1000;
	sim->max_time[SLEEP] = ft_atou(argv[4]) * 1000;
	if (argv[5] != NULL)
		sim->total_meals = ft_atou(argv[5]);
	else
		sim->total_meals = 0;
	sim->philo = (t_philo *)malloc(sizeof(t_philo) * sim->total_philos);
	sim->mutex_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* sim->total_philos);
}
