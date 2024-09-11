/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:35:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/26 17:13:40 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nbr)
{
	int	bytes;
	int	temp;

	bytes = 0;
	if (nbr < 10)
	{
		bytes = ft_print_char((nbr + '0'));
		return (bytes);
	}
	temp = ft_print_unsigned((nbr / 10));
	if (temp == -1)
		return (temp);
	bytes = temp;
	temp = ft_print_unsigned((nbr % 10));
	if (temp == -1)
		return (temp);
	bytes += temp;
	return (bytes);
}
