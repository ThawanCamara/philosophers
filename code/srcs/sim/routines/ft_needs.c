/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_needs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:45:43 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 08:45:43 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (ft_is_simulation_active(philo) == 0)
		return ;
	pthread_mutex_lock(&philo->mutex[LAST_MEAL]);
	philo->last_meal = ft_time_elapsed(philo->sim, ft_get_instant());
	pthread_mutex_unlock(&philo->mutex[LAST_MEAL]);
	ft_print_state(philo, EATING);
	pthread_mutex_lock(&philo->mutex[STATE]);
	philo->state = EATING;
	pthread_mutex_unlock(&philo->mutex[STATE]);
	ft_wait(philo, philo->sim->max_time[EAT]);
	pthread_mutex_lock(&philo->mutex[MEALS_EATEN]);
	if (philo->sim->total_meals > 0)
		philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex[MEALS_EATEN]);
}

void	ft_sleep(t_philo *philo)
{
	if (ft_is_simulation_active(philo) == 0)
		return ;
	ft_print_state(philo, SLEEPING);
	philo->state = SLEEPING;
	ft_wait(philo, philo->sim->max_time[SLEEP]);
}

/*
 * The usleep in the end prevents a philosopher from surpassing a waiting
 * philosopher in the mutex queue.
 */
void	ft_think(t_philo *philo)
{
	if (ft_is_simulation_active(philo) == 0)
		return ;
	ft_print_state(philo, THINKING);
	philo->state = THINKING;
	usleep(1000);
}
