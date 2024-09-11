/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:16:02 by jwolfram          #+#    #+#             */
/*   Updated: 2024/05/13 15:17:14 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*chr;

	chr = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			chr = (unsigned char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return ((char *)chr);
}
