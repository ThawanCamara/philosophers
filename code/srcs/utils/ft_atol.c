/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:29:43 by tde-souz          #+#    #+#             */
/*   Updated: 2022/11/10 04:12:22 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_atol(const char *str)
{
	unsigned long	num;

	num = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v'
		|| *str == '\f' || *str == ' ')
	{
		str++;
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	return (num);
}
