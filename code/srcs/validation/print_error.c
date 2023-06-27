/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:12:30 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/19 08:34:05 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

// Prints an error message in the terminal.
int	print_error(char *msg)
{
	printf(">>> %sError%s <<<\n", B_RED, RESET);
	printf("%s\n", msg);
	return (-1);
}
