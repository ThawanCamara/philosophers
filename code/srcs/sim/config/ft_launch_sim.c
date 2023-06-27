/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_sim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:21 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 18:34:47 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * Launches the simulation by first initializing the mutexes then creating the
 * threads that are going to be used as philosophers. The monitoring code is
 * then put into use to check whether the simulation should end due to one of
 * the philosophers having passed away. When the simulation is marked as over
 * the threads are joined and mutexes destroyed.
 */
void	ft_launch_sim(t_sim *sim)
{
	ft_init_mutexes(sim);
	sim->sim_running = 1;
	sim->launch_time = ft_get_instant();
	ft_create_threads(sim);
	usleep(1000);
	ft_monitoring(sim);
	ft_join_threads(sim);
	ft_destroy_mutexes(sim);
}
