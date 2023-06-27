/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:43:42 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 08:43:42 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static unsigned int	ft_get_rfork(t_philo *philo);
static unsigned int	ft_get_lfork(t_philo *philo);
static void			lock_fork(t_philo *philo,
						unsigned int (*f1)(t_philo *philo),
						unsigned int (*f2)(t_philo *philo));

/*
 * Philosophers with an even id will take the fork to the right as their first
 * fork and those with an odd id will first go to the leftmost fork. This logic
 * ensures that there will be no deadlocks.
*/
void	ft_take_forks(t_philo *philo)
{
	if (ft_is_simulation_active(philo) == 0)
		return ;
	if (philo->id % 2 == 0)
		lock_fork(philo, ft_get_rfork, ft_get_lfork);
	else
		lock_fork(philo, ft_get_lfork, ft_get_rfork);
}

// The given philosopher returns both forks to the table.
void	ft_return_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->sim->mutex_forks[ft_get_rfork(philo)]);
	if (philo->sim->total_philos >= 2)
		pthread_mutex_unlock(&philo->sim->mutex_forks[ft_get_lfork(philo)]);
}

// Locks the mutexes needed to eat.
static void	lock_fork(t_philo *philo, unsigned int (*f1)(t_philo *philo),
				unsigned int (*f2)(t_philo *philo))
{
	pthread_mutex_lock(&philo->sim->mutex_forks[f1(philo)]);
	ft_print_state(philo, TAKEN_FORKS);
	if (philo->sim->total_philos < 2)
		while (1)
			if (ft_is_simulation_active(philo) == 0)
				return ;
	pthread_mutex_lock(&philo->sim->mutex_forks[f2(philo)]);
	ft_print_state(philo, TAKEN_FORKS);
	pthread_mutex_lock(&philo->mutex[STATE]);
	philo->state = TAKEN_FORKS;
	pthread_mutex_unlock(&philo->mutex[STATE]);
}

static unsigned int	ft_get_rfork(t_philo *philo)
{
	if (philo->id == 0)
		return (philo->sim->total_philos - 1);
	else
		return (philo->id - 1);
}

static unsigned int	ft_get_lfork(t_philo *philo)
{
	return (philo->id);
}
