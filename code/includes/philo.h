/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:21:33 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/22 21:52:32 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include "validation.h"
# include "colortag.h"

# define MAX_PHILO_MUTEXES 3
# define MAX_SIM_MUTEXES 3

/* ************************************************************************** */
/*								   ENUMERATIONS								  */
/* ************************************************************************** */

enum e_time_types
{
	EAT = 0,
	SLEEP = 1,
	DIE = 2
};

enum e_philo_mutexes_types
{
	STATE = 0,
	MEALS_EATEN = 1,
	LAST_MEAL = 2
};

enum e_sim_mutexes_types
{
	SIM_RUNNING = 0,
	PRINT = 1,
	DEATH = 2
};

enum e_state_types
{
	TAKEN_FORKS = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	DIED = 4,
	FINISH = 5
};

/* ************************************************************************** */
/*									 STRUCTS								  */
/* ************************************************************************** */

typedef struct s_philo
{
	unsigned int		id;
	int					state;
	unsigned int		meals_eaten;
	unsigned long		last_meal;
	struct s_sim		*sim;
	pthread_t			thread;
	pthread_mutex_t		mutex[MAX_PHILO_MUTEXES];
}	t_philo;

typedef struct s_sim
{
	unsigned int		sim_running;
	unsigned int		total_philos;
	unsigned int		total_meals;
	unsigned long		max_time[3];
	unsigned long		launch_time;
	struct s_philo		*philo;
	pthread_mutex_t		*mutex_forks;
	pthread_mutex_t		mutex[MAX_SIM_MUTEXES];
}	t_sim;

/* ************************************************************************** */
/*									SIMULATION								  */
/* ************************************************************************** */

void			ft_init_sim(t_sim *sim, char *argv[]);
void			ft_init_philo(t_sim *sim);
void			ft_launch_sim(t_sim *sim);
void			ft_clear_sim(t_sim *sim);
void			*ft_philo_sim(void *data);
void			ft_monitoring(t_sim *sim);
void			ft_terminate_sim(t_sim *sim);

/* ************************************************************************** */
/*									  CHECKS								  */
/* ************************************************************************** */

int				ft_is_sim_running(t_sim *sim);
int				ft_is_philo_alive(t_philo *philo);
int				ft_has_eaten_all(t_philo *philo);
int				ft_is_simulation_active(t_philo *philo);

/* ************************************************************************** */
/*									 ROUTINES								  */
/* ************************************************************************** */

void			ft_take_forks(t_philo *philo);
void			ft_return_forks(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo);
void			ft_think(t_philo *philo);

/* ************************************************************************** */
/*								THREADS & MUTEXES							  */
/* ************************************************************************** */

void			ft_create_threads(t_sim *sim);
void			ft_join_threads(t_sim *sim);
void			ft_init_mutexes(t_sim *sim);
void			ft_destroy_mutexes(t_sim *sim);

/* ************************************************************************** */
/*									  TIMER									  */
/* ************************************************************************** */

unsigned long	ft_get_instant(void);
unsigned long	ft_time_elapsed(t_sim *sim, unsigned long moment);
void			ft_wait(t_philo *philo, unsigned long duration);

/* ************************************************************************** */
/*									   UTILS								  */
/* ************************************************************************** */

unsigned long	ft_atou(char *str);
unsigned long	ft_atol(char *str);
void			ft_print_state(t_philo *philo, int state);

#endif
