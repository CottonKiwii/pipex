/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:55:01 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/11 19:16:32 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_allocate(char *str, int len, int n)
{
	int	res;

	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (len == 1)
	{
		str[0] = n + '0';
		return (str);
	}
	while (len > 0)
	{
		len--;
		res = n % 10 + '0';
		if (n < 0)
			res = (n % 10) * -1 + '0';
		str[len] = res;
		n /= 10;
	}
	if (str[0] == '0')
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	str = 0;
	len = 0;
	if (n == -2147483648)
	{
		str = ft_allocate(str, 11, n);
		return (str);
	}
	len = ft_intlen(n);
	str = ft_allocate(str, len, n);
	return (str);
}
