/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sim_running.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:21:04 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 09:21:04 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_sim_running(t_sim *sim)
{
	int	check;

	pthread_mutex_lock(&sim->mutex[SIM_RUNNING]);
	if (sim->sim_running == 1)
		check = 1;
	else
		check = 0;
	pthread_mutex_unlock(&sim->mutex[SIM_RUNNING]);
	return (check);
}
