/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:21:50 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 11:21:50 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * Prints the state of a given philosopher to the terminal only if the state
 * passed as argument is different from the actual state of the philosopher.
 */
void	ft_print_state(t_philo *philo, int state)
{
	unsigned long	instant;
	const char		*message[] = {"has taken a fork", "is eating",
		"is sleeping", "is thinking", "died"};

	if (ft_is_sim_running(philo->sim))
	{
		pthread_mutex_lock(&philo->sim->mutex[PRINT]);
		pthread_mutex_lock(&philo->mutex[STATE]);
		instant = ft_time_elapsed(philo->sim, ft_get_instant());
		if (state != philo->state && philo->state < 5)
			printf("%lu %u %s\n", instant / 1000, philo->id + 1, message[state]);
		pthread_mutex_unlock(&philo->mutex[STATE]);
		pthread_mutex_unlock(&philo->sim->mutex[PRINT]);
	}
}
