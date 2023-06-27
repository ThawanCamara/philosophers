/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_sim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:06:03 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 18:35:47 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Free m'allocated memory used in the setup part of this project.
void	ft_clear_sim(t_sim *sim)
{
	free(sim->mutex_forks);
	free(sim->philo);
}
