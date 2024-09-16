/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:36:34 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/16 16:50:47 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_wordcount(char *str, char c)
{
	int	i;
	int	words;
	int	swch;

	i = 0;
	words = 0;
	while (str && str[i] != c)
		i++;
	if (i)
		words++;
	while (str)
	{
		if (str[i] == c && str[i + 1] != c)
			words++;
		if ((str[i] == '"' || str[i] == '\'') && swch)
		{
			swch = 0;
			words++;
		}
		else
			swch = 1;
	}
	return (words);
}
