/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:08:05 by jwolfram          #+#    #+#             */
/*   Updated: 2024/05/13 15:29:44 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	if (s[i] != c && s[i])
	{
		word++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			word++;
		i++;
	}
	return (word);
}

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = 0;
}

static int	ft_findstr(char **arr, const char *s, char c, int i)
{
	int		len;
	int		words;
	char	*str;

	len = 0;
	while (s[i + len] && s[i + len] != c)
		len++;
	str = ft_substr(s, i, len);
	if (!str)
	{
		ft_free(arr);
		return (0);
	}
	words = 0;
	while (arr[words])
		words++;
	arr[words] = str;
	return (1);
}

static int	ft_arrange(char **arr, const char *s, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (s[i] && arr)
	{
		if (i == 0 && s[i] != c && s[i])
			check = ft_findstr(arr, s, c, i);
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			check = ft_findstr(arr, s, c, (i + 1));
		if (!check)
			return (0);
		i++;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		word;

	if (!s)
		return (NULL);
	word = ft_wordcount(s, c);
	arr = (char **)ft_calloc((word + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	if (!ft_arrange(arr, s, c))
		return (NULL);
	return (arr);
}
