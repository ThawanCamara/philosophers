/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate_sim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:26:58 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/21 10:26:58 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_terminate_sim(t_sim *sim)
{
	pthread_mutex_lock(&sim->mutex[SIM_RUNNING]);
	sim->sim_running = 0;
	pthread_mutex_unlock(&sim->mutex[SIM_RUNNING]);
}
