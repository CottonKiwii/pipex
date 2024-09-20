/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:04:05 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/20 14:20:03 by jwolfram         ###   ########.fr       */
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

int	ft_check_access(t_struct *stc, t_cmd *cur, char *enpath)
{
	char	*path_tmp;

	path_tmp = ft_strdup(enpath);
	if (!path_tmp)
		ft_exit(stc, ERR);
	path_tmp = ft_strjoin(path_tmp, cur->args[0]);
	if (!path_tmp)
		ft_exit(stc, ERR);
	if (!access(path_tmp, X_OK))
	{
		if (cur->path)
			ft_null(&cur->path);
		cur->path = path_tmp;
		return (1);
	}
	if (!access(path_tmp, F_OK))
	{
		if (cur->path)
			ft_null(&cur->path);
		cur->path = path_tmp;
		return (0);
	}
	free(path_tmp);
	return (0);
}
