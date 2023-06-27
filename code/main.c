/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:23:44 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 15:27:21 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_sim	sim;

	if (validation(argc, argv) != 0)
		return (1);
	ft_init_sim(&sim, argv);
	ft_init_philo(&sim);
	ft_launch_sim(&sim);
	ft_clear_sim(&sim);
	return (0);
}
