/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:02:19 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/11 11:27:54 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src && n)
		return (dest);
	while (i < n)
	{
		if (dest < src)
			((char *)dest)[i] = ((char *)src)[i];
		else
			((char *)dest)[n - i - 1] = ((char *)src)[n - i - 1];
		i++;
	}
	return (dest);
}
