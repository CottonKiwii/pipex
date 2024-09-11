/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:34:13 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/29 13:54:24 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_set_nbr(int nbr, int mod)
{
	int	bytes;
	int	temp;

	bytes = 0;
	if (nbr < 10 && nbr > -10)
	{
		bytes = ft_print_char((nbr * mod) + '0');
		return (bytes);
	}
	temp = ft_set_nbr((nbr / 10), mod);
	if (temp == -1)
		return (temp);
	bytes += temp;
	temp = ft_set_nbr((nbr % 10), mod);
	if (temp == -1)
		return (temp);
	bytes += temp;
	return (bytes);
}

int	ft_print_nbr(int nbr)
{
	int	mod;
	int	bytes;
	int	temp;

	mod = 1;
	bytes = 0;
	if (nbr < 0)
	{
		temp = write(STDOUT_FILENO, "-", 1);
		if (temp == -1)
			return (temp);
		bytes = temp;
		mod = -1;
	}
	temp = ft_set_nbr(nbr, mod);
	if (temp == -1)
		return (temp);
	bytes += temp;
	return (bytes);
}
