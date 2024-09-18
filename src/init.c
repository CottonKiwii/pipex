/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:29:33 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/18 11:08:08 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_args(t_cmd *node, t_struct *stc)	
{
	int		i;
	char	**tmp;

	i = 0;
	if (!node->path || ft_strchr(node->path, '"') 
		|| ft_strchr(node->path, '\''))
		ft_exit(stc, FALSE);
	tmp = ft_split(node->path, ' ');
	node->path = NULL;
	if (!tmp)
	{
		perror("pipex");
		ft_exit(stc, FALSE);
	}
	node->args = tmp;
	node->path = ft_strdup(node->args[0]);
}

void	commands_init(t_struct *stc)
{
	int		i;
	t_cmd	*node;
	t_cmd	*tmp;

	i = 2;
	tmp = NULL;
	while (i < (stc->ac - 1))
	{
		node = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
		if (!node)
			ft_exit(stc, FALSE);
		if (tmp)
			tmp->next = node;
		node->path = stc->av[i];
		if (i == 2)
			stc->cmd = node;
		get_args(node, stc);
		tmp = node;
		i++;
	}
}

void	open_file(t_struct *stc)
{
	stc->infile = open(stc->av[1], O_RDONLY);
	if (stc->infile == RDERR)
		perror("pipex");
}

void	stc_init(t_struct *stc, int ac, char **av, char **env)
{
	stc->ac = ac;	
	stc->av = av;
	stc->env = env;
	stc->cmd = NULL;
	stc->enpath = NULL;
	stc->outfile = -1;
	open_file(stc);
	commands_init(stc);
}

char	*path_init(t_struct *stc)
{
	int	i;

	i = 0;
	while (stc->env[i])
	{
		if (ft_strncmp(stc->env[i], "PATH=", 5) == 0) 
			return (stc->env[i]);
		i++;
	}
	return (NULL);
}
