/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:30:19 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/03 22:32:04 by CottonKiwii      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int		bytes;
	int		len;

	bytes = 0;
	if (!str)
	{
		bytes = write(STDOUT_FILENO, "(null)", 6);
		return (bytes);
	}
	len = ft_strlen(str);
	bytes += write(STDOUT_FILENO, str, len);
	return (bytes);
}
