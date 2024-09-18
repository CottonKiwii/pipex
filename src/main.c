/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:37:47 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/18 11:14:36 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_access(t_struct *stc)
{
	t_cmd	*cur;

	cur = stc->cmd;
	while (cur)
	{
		ft_printf("Command Path is %s\n", cur->path);
		cur = cur->next;
	}
}

void	get_paths(t_struct *stc)
{
	char	*all_paths;

	all_paths = path_init(stc);
	if (!all_paths)
		return ;
	all_paths = ft_substr(all_paths, 5, (ft_strlen(all_paths) - 5));
	if (!all_paths)
		ft_exit(stc, FALSE);
	stc->enpath = ft_split(all_paths, ':');
	free(all_paths);
	if (!stc->enpath)
		ft_exit(stc, FALSE);
}

int	main(int ac, char **av, char **env)
{
	t_struct	stc;

	if (ac < 5)
		return (write(2, "pipex: Invalid Arguments\n", 25), FALSE);
	stc_init(&stc, ac, av, env); // KEEP IN MIND IF INFILE IS -1 FOR LATER!
	get_paths(&stc); // KEEP IN MIND IF PATH IS NULL FOR LATER!
	get_access(&stc);
	ft_exit(&stc, 0);
}
