/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:11:08 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/03 21:53:27 by CottonKiwii      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s2)
		return (NULL);
	len = 0;
	if (s1)
		len = ft_strlen(s1);
	str = (char *)ft_calloc(len + ft_strlen(s2) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[i + len] = s2[i];
		i++;
	}
	return (str);
}
