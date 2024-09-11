/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:28:45 by jwolfram          #+#    #+#             */
/*   Updated: 2024/05/13 15:33:22 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, const char *set)
{
	while (*set && *set != c)
		set++;
	if (*set == c)
		return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char			*res;
	size_t			rlen;
	size_t			start;
	size_t			i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	while (s1[i] && ft_isinset(s1[i], set))
		i++;
	start = i;
	while (s1[i])
	{
		if (!ft_isinset(s1[i], set))
			rlen = i;
		i++;
	}
	res = ft_substr(s1, start, rlen - start + 1);
	if (!res)
		return (NULL);
	return (res);
}
