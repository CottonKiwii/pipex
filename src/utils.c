/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:36:34 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/19 13:37:57 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_open_file(t_struct *stc, t_nbr file)
{
	if (file == INFILE)
	{
		stc->infile = open(stc->av[1], O_RDONLY);
		if (stc->infile == RDERR)
			perror("pipex");
		else
			ft_wrap_dup(stc, stc->infile, STDIN_FILENO);
	}
	else
	{
		stc->outfile = open(stc->av[stc->ac - 1], WR | CR | TR, 0644);
		if (stc->outfile == RDERR)
			perror("pipex");
	}
}
