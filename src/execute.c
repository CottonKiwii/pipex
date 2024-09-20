/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:42:57 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/20 12:11:11 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	kill_child(t_struct *stc, t_cmd *cmd)
{
	if (!access(cmd->path, F_OK))
		ft_exit(stc, 126);
	if (ft_strchr(cmd->path, '/'))
		ft_putstr_fd("pipex: No such file or directory\n", STDERR_FILENO);
	else
		ft_putstr_fd("pipex: Command not found\n", STDERR_FILENO);
	errno = 0;
	ft_exit(stc, 127);
}

void	execute_child(t_struct *stc, t_cmd *cmd, int fd[2])
{
	close(fd[0]);
	if (cmd->nbr == 1 && stc->infile == -1)
	{
		close(fd[1]);
		ft_exit(stc, ERR);
	}
	if (cmd->nbr == (stc->ac - 3))
	{
		ft_dup(stc, stc->outfile, STDOUT_FILENO);
		close(fd[1]);
	}
	else
		ft_dup(stc, fd[1], STDOUT_FILENO);
	if (execve(cmd->path, cmd->args, stc->env) == -1)
		kill_child(stc, cmd);
}

pid_t	ft_execute(t_struct *stc, t_cmd *cmd)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_exit(stc, ERR);
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		ft_exit(stc, ERR);
	}
	else if (pid == 0)
		execute_child(stc, cmd, fd);
	close(fd[1]);
	if (cmd->nbr == (stc->ac - 3))
		close(fd[0]);
	else
		ft_dup(stc, fd[0], STDIN_FILENO);
	return (pid);
}
