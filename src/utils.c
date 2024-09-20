/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:04:05 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/20 11:06:09 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup(t_struct *stc, int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) == -1)
	{
		close(old_fd);
		ft_exit(stc, ERR);
	}
	close(old_fd);
}

void	ft_open_file(t_struct *stc, t_nbr file)
{
	if (file == INFILE)
	{
		stc->infile = open(stc->av[1], O_RDONLY);
		if (stc->infile == RDERR)
			perror("pipex");
		else
			ft_dup(stc, stc->infile, STDIN_FILENO);
	}
	else
	{
		stc->outfile = open(stc->av[stc->ac - 1], WR | CR | TR, 0644);
		if (stc->outfile == RDERR)
			perror("pipex");
	}
	errno = 0;
}
