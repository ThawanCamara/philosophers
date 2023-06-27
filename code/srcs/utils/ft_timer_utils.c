/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:06:01 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 15:06:34 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Returns the current time in microsseconds.
unsigned long	ft_get_instant(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

// Returns the amount of time in microsseconds since simulation start.
unsigned long	ft_time_elapsed(t_sim *sim, unsigned long moment)
{
	return (moment - sim->launch_time);
}

// Causes execution to halt for a specified duration or until simulation ends. 
void	ft_wait(t_philo *philo, unsigned long duration)
{
	unsigned long	start;

	start = ft_get_instant();
	while (ft_is_simulation_active(philo)
		&& ft_get_instant() - start < duration)
		usleep(150);
}
