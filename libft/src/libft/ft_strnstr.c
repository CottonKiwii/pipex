/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:55:31 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/16 19:24:29 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;

	if (!*little)
		return ((char *)big);
	if (!len)
		return (NULL);
	llen = ft_strlen(little);
	if (!llen || !*big)
		return (NULL);
	while (*big && len >= llen)
	{
		if (ft_memcmp(big, little, llen) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
