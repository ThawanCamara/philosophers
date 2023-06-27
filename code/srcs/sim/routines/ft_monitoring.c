/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 04:35:44 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/21 10:29:00 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	stop_if_meals_eaten(t_sim *sim);

void	ft_monitoring(t_sim *sim)
{
	unsigned int	i;
	int				state;

	while (ft_is_sim_running(sim))
	{
		i = 0;
		if (sim->total_meals > 0)
			stop_if_meals_eaten(sim);
		while (i < sim->total_philos)
		{
			pthread_mutex_lock(&sim->philo[i].mutex[STATE]);
			state = sim->philo[i].state;
			pthread_mutex_unlock(&sim->philo[i].mutex[STATE]);
			if (state != FINISH)
				if (ft_is_philo_alive(&sim->philo[i]) == 0)
					break ;
			i++;
			usleep(100);
		}
	}
}

static void	stop_if_meals_eaten(t_sim *sim)
{
	unsigned int	i;
	unsigned int	sum;

	i = 0;
	sum = 0;
	while (i < sim->total_philos)
	{
		pthread_mutex_lock(&sim->philo[i].mutex[MEALS_EATEN]);
		if (sim->philo[i].meals_eaten == sim->total_meals)
			sum++;
		else
		{
			pthread_mutex_unlock(&sim->philo[i].mutex[MEALS_EATEN]);
			break ;
		}
		if (sum == sim->total_philos)
			ft_terminate_sim(sim);
		pthread_mutex_unlock(&sim->philo[i].mutex[MEALS_EATEN]);
		i++;
	}
}
