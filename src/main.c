/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:37:47 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/13 17:18:14 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_paths(t_struct *stc)
{
	char	*all_paths;
	char	**paths;

	all_paths = path_init(stc);
	if (!all_paths)
		return ;
	all_paths = ft_substr(all_paths, 5, (ft_strlen(all_paths) - 5));
	if (!all_paths)
		exit(1); // ADD A FACKEN FREE FOR YO STRUCT!!!
	stc->path = ft_split(all_paths, ':');
	if (!stc->path)
		exit(1); // ADD A FACKEN FREE FOR YO STRUCT!!!
}

void	open_file(t_struct *stc)
{
	stc->infile = open(stc->av[1], O_RDONLY);
	if (stc->infile == -1)
		perror("pipex");
}

int	main(int ac, char **av, char **env)
{
	t_struct	stc;

	if (ac < 5)
		return (1);
	stc_init(&stc, ac, av, env); // KEEP IN MIND IF INFILE IS -1 FOR LATER!
	get_paths(&stc); // KEEP IN MIND IF PATH IS NULL FOR LATER!
}
