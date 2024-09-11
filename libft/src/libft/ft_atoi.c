/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:59:31 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/16 14:07:37 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(const char *nptr)
{
	if (*nptr == ' ' || *nptr == '\t' || *nptr == '\r'
		|| *nptr == '\n' || *nptr == '\v' || *nptr == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	res;

	neg = 1;
	res = 0;
	while (ft_isspace(nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg *= -1;
		nptr++;
	}
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * neg);
}
