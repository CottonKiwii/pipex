/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:28:14 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/16 19:21:43 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	if (!dst && !size)
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen >= size)
		dlen = size;
	if (dlen == size)
		return (dlen + slen);
	if (slen < size - dlen)
		ft_memcpy(dst + dlen, src, slen + 1);
	else
	{
		ft_memcpy(dst + dlen, src, size - dlen - 1);
		dst[size - 1] = '\0';
	}
	return (dlen + slen);
}
