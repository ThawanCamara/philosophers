/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_philo_alive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:33:26 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 10:33:26 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Check if a given philosopher is still alive.
int	ft_is_philo_alive(t_philo *philo)
{
	int	check;

	pthread_mutex_lock(&philo->mutex[LAST_MEAL]);
	if (ft_is_sim_running(philo->sim)
		&& ft_time_elapsed(philo->sim, ft_get_instant() - philo->last_meal)
		>= philo->sim->max_time[DIE])
	{
		pthread_mutex_lock(&philo->sim->mutex[DEATH]);
		ft_print_state(philo, DIED);
		pthread_mutex_lock(&philo->mutex[STATE]);
		philo->state = DIED;
		pthread_mutex_unlock(&philo->mutex[STATE]);
		ft_terminate_sim(philo->sim);
		check = 0;
	}
	else
		check = 1;
	pthread_mutex_unlock(&philo->mutex[LAST_MEAL]);
	return (check);
}
