/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:51:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/20 14:17:12 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_commands(t_struct *stc)
{
	t_cmd	*cur;
	int		status;
	pid_t	pid;

	cur = stc->cmd;
	while (cur && cur->nbr != (stc->ac - 3))
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
		return (ft_putstr_fd("pipex: Invalid Arguments\n", STDERR_FILENO), ERR);
	stc_init(&stc, ac, av, env);
	get_paths(&stc);
	get_access(&stc);
	execute_commands(&stc);
}
