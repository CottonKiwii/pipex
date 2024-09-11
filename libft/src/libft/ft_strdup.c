/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:13:44 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/16 19:37:06 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;

	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, ft_strlen(s) + 1);
	return (res);
}
