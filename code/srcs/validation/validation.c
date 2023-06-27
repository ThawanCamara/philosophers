/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:13:35 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 08:40:16 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

/*
 * Centralizes input validation tests for this project. Whether it is:
 * - Empty parameters.
 * - Use of invalid characters.
 * - Less than 3 values provided.
 * - More than 4 values provided.
 * - Overflow of a given value.
 * - No philosopher to simulate.
*/
int	validation(int argc, char *argv[])
{
	if (argc == 1)
		return (print_error("No arguments provided."));
	if (check_string((argv + 1)) != 0)
		return (print_error("Invalid characters used."));
	if (argc < 5)
		return (print_error("Too few arguments."));
	if (argc > 6)
		return (print_error("Too many arguments."));
	if (check_typelimit(argv + 1))
		return (print_error("Value overflows the type's limit."));
	if (ft_atou(argv[1]) == 0)
		return (print_error("No philosopher to simulate."));
	return (0);
}
