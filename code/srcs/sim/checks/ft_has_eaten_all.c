/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meals_eaten.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:28:05 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 10:28:05 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Check if a given philosopher has eaten all of its required meals.
int	ft_has_eaten_all(t_philo *philo)
{
	int	check;

	pthread_mutex_lock(&philo->mutex[MEALS_EATEN]);
	if (philo->meals_eaten < philo->sim->total_meals
		|| philo->sim->total_meals == 0)
		check = 0;
	else
		check = 1;
	pthread_mutex_unlock(&philo->mutex[MEALS_EATEN]);
	return (check);
}
