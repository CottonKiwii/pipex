/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:32:33 by jwolfram          #+#    #+#             */
/*   Updated: 2024/05/07 11:43:18 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int	bytes;
	int	temp;

	if (!ptr)
		return (write(STDOUT_FILENO, "(nil)", 5));
	temp = ft_print_str("0x");
	if (temp == -1)
		return (temp);
	bytes = temp;
	temp = ft_print_hex((unsigned long)ptr, 'x');
	if (temp == -1)
		return (temp);
	bytes += temp;
	return (bytes);
}
