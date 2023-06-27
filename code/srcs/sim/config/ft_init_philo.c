/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:19:04 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 15:27:49 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Initializes all philosophers' struct data with default parameters.
void	ft_init_philo(t_sim *sim)
{
	unsigned int	i;

	i = 0;
	while (i < sim->total_philos)
	{
		sim->philo[i].id = i;
		sim->philo[i].state = THINKING;
		sim->philo[i].last_meal = 0;
		sim->philo[i].meals_eaten = 0;
		sim->philo[i].sim = sim;
		i++;
	}
}
