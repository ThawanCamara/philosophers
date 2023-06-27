/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_sim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 08:53:51 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_last_meal(t_philo *philo);

// Simulate a philosopher from 42's Dining Philosophers Problem.
void	*ft_philo_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	init_last_meal(philo);
	while (ft_is_simulation_active(philo) && ft_has_eaten_all(philo) == 0)
	{
		ft_take_forks(philo);
		ft_eat(philo);
		ft_return_forks(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	pthread_mutex_lock(&philo->mutex[STATE]);
	philo->state = FINISH;
	pthread_mutex_unlock(&philo->mutex[STATE]);
	pthread_mutex_unlock(&philo->sim->mutex[DEATH]);
	return (NULL);
}

// Initializes a philosopher's last meal as the current instant.
static void	init_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex[LAST_MEAL]);
	philo->last_meal = ft_time_elapsed(philo->sim, ft_get_instant());
	pthread_mutex_unlock(&philo->mutex[LAST_MEAL]);
}
