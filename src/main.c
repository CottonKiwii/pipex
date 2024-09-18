/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:37:47 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/18 17:25:55 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute(t_struct *stc, t_cmd *cmd)
{
	int	error;

	if (cmd->nbr == (stc->ac - 2))
		return ; // HANDLE LAST COMMAND DIFFERENTLY
	error = execve(cmd->path, cmd->args, stc->env);
	if (error)
		perror("pipex");
}

void	fd_to_stdin(t_struct *stc, int fd)
{
	int error;
	
	if (fd == RDERR)
		return ;
	error = dup2(fd, STDIN_FILENO);
}

int	main(int ac, char **av, char **env)
{
	t_struct	stc;

	if (ac < 5)
		return (write(2, "pipex: Invalid Arguments\n", 25), ERR);
	stc_init(&stc, ac, av, env); // KEEP IN MIND IF INFILE IS -1 FOR LATER!
	get_paths(&stc);
	get_access(&stc);
	ft_execute(&stc, stc.cmd);
	ft_exit(&stc, 0);
}
