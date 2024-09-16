/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:37:47 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/16 17:59:20 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_access(t_struct *stc)
{

}

void	get_paths(t_struct *stc)
{
	char	*all_paths;

	all_paths = path_init(stc);
	if (!all_paths)
		return ;
	all_paths = ft_substr(all_paths, 5, (ft_strlen(all_paths) - 5));
	if (!all_paths)
		ft_exit(stc, 1);
	stc->path = ft_split(all_paths, ':');
	free(all_paths);
	if (!stc->path)
		ft_exit(stc, 1);
}

void	open_file(t_struct *stc)
{
	stc->infile = open(stc->av[1], O_RDONLY);
	if (stc->infile == RDERR)
		perror("pipex");
}

#include "ft_printf.h"
int	main(int ac, char **av, char **env)
{
	t_struct	stc;

	if (ac < 5)
		return (1);
	stc_init(&stc, ac, av, env); // KEEP IN MIND IF INFILE IS -1 FOR LATER!
	get_paths(&stc); // KEEP IN MIND IF PATH IS NULL FOR LATER!
	
	int		i;
	t_cmd	*cur;
	for (i = 0; stc.path[i]; i++)
		ft_printf("Path is %s\n", stc.path[i]);
	ft_printf("Argc is %d\n", stc.ac);
	for (i = 0; stc.av[i]; i++)
		ft_printf("Argv is %s\n", stc.av[i]);
	for (i = 0; stc.env[i]; i++)
		ft_printf("Environment is %s\n", stc.env[i]);
	ft_printf("Infile is %d\n", stc.infile);
	cur = stc.cmd;
	while (cur)
	{
		ft_printf("Command Path is %s\n", cur->path);
		for (i = 0; cur->args[i]; i++)
			ft_printf("Command Arg is %s\n", cur->args[i]);
		cur = cur->next;
	}
//	get_access(&stc);
}
