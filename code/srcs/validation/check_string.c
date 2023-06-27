/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:45:50 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 08:31:39 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	check_char(char *str);

// Checks the strings from the input for invalid characters.
int	check_string(char *argv[])
{
	while (*argv)
	{
		if (check_char(*argv) != 0)
			return (-1);
		argv++;
	}
	return (0);
}

// Checks if a character used is either a digit or a valid '+' sign.
static int	check_char(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] == '+' && i == 0 && str[i + 1] >= '0'
				&& str[i + 1] <= '9'))
			i++;
		else
			return (-1);
	}
	return (0);
}
