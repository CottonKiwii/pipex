/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:28:28 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/16 19:12:46 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*u;

	u = s;
	while (n-- > 0)
	{
		if (*u == (unsigned char)c)
			return ((void *)u);
		u++;
	}
	return (NULL);
}
