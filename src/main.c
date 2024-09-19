/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:51:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/19 18:05:15 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	kill_child(t_struct *stc, t_cmd *cmd)
{
	(void)cmd;
	dprintf(STDERR_FILENO, "i am very sad %s\n", cmd->path);
	ft_exit(stc, ERR);
}

void	ft_wrap_dup(t_struct *stc, int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) == -1)
	{
		close(old_fd);
		ft_exit(stc, ERR);
	}
	close(old_fd);
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
		ft_wrap_dup(stc, stc->outfile, STDOUT_FILENO);
		close(fd[1]);
	}
	else
		ft_wrap_dup(stc, fd[1], STDOUT_FILENO);
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
		ft_wrap_dup(stc, fd[0], STDIN_FILENO);
	return (pid);
}

void	fd_to_stdin(t_struct *stc, int fd)
{
	int error;
	
	if (fd == RDERR)
		return ;
	error = dup2(fd, STDIN_FILENO);
	if (error == -1)
		ft_exit(stc, ERR);
	close(fd);
}

void	fd_to_stdout(t_struct *stc, int fd)
{
	int error;

	if (fd == RDERR)
		return ;
	error = dup2(fd, STDOUT_FILENO);
	if (error == -1)
		ft_exit(stc, ERR);
	close(fd);
}

void	execute_commands(t_struct *stc)
{
	t_cmd	*cur;
	int		status;
	pid_t	pid;
	
	cur = stc->cmd;
	while(cur && cur->nbr != (stc->ac - 3))
	{
		ft_execute(stc, cur);
		cur = cur->next;
	}
	ft_open_file(stc, OUTFILE);
	if (stc->outfile == -1)
		ft_exit(stc, ERR);
	pid = ft_execute(stc, cur);
	if (waitpid(pid, &status, 0) == -1)
		ft_exit(stc, ERR);
	if (WIFEXITED(status))
		ft_exit(stc, WEXITSTATUS(status));
	ft_exit(stc, ERR);
}

int	main(int ac, char **av, char **env)
{
	t_struct	stc;

	if (ac < 5)
		return (write(2, "pipex: Invalid Arguments\n", 25), ERR);
	stc_init(&stc, ac, av, env); // KEEP IN MIND IF INFILE IS -1 FOR LATER!
	get_paths(&stc);
	get_access(&stc);
	execute_commands(&stc);
}
