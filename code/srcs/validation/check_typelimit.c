/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_typelimit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:50:57 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 11:57:52 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	check_overflow(char *str);

// Loops through the list of arguments to test the limits of provided values.
int	check_typelimit(char *argv[])
{
	while (*argv)
	{
		if (check_overflow(*argv) != 0)
			return (-1);
		argv++;
	}
	return (0);
}

// If a provided argument overflows max unsigned int then returns -1.
static int	check_overflow(char *str)
{
	int			len;
	long int	num;
	long int	mult;

	len = 0;
	num = 0;
	mult = 1;
	while (str[len])
		len++;
	while (len >= 0)
	{
		if (str[len] >= '0' && str[len] <= '9')
		{
			num += (str[len] - '0') * mult;
			mult *= 10;
		}
		len--;
		if (num > (long int)U_MAX)
			return (-1);
	}
	return (0);
}
