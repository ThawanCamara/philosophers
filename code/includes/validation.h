/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:21:17 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/06 13:37:18 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "philo.h"

# ifndef U_MAX
#  define U_MAX 4294967295
# endif

int	validation(int argc, char *argv[]);
int	print_error(char *msg);
int	check_string(char *argv[]);
int	check_typelimit(char *argv[]);

#endif
