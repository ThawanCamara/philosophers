/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_simulation_active.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:04 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 12:03:04 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Tests if the simulation is still valid for this philosopher.
int	ft_is_simulation_active(t_philo *philo)
{
	return (ft_is_sim_running(philo->sim) && ft_is_philo_alive(philo));
}
