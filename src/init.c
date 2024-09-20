/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:29:33 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/20 14:18:07 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	node_init(t_struct *stc, t_cmd *node, t_cmd *tmp, int count)
{
	if (count == 1)
		stc->cmd = node;
	else
		tmp->next = node;
	node->nbr = count;
	if (!node->path)
		ft_exit(stc, ERR);
	get_args(node, stc);
}

void	commands_init(t_struct *stc)
{
	int		i;
	int		count;
	t_cmd	*node;
	t_cmd	*tmp;

	i = 2;
	count = 1;
	tmp = NULL;
	while (i < (stc->ac - 1))
	{
		node = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
		if (!node)
			ft_exit(stc, ERR);
		node->path = ft_strdup(stc->av[i]);
		node_init(stc, node, tmp, count);
		tmp = node;
		count++;
		i++;
	}
}

void	stc_init(t_struct *stc, int ac, char **av, char **env)
{
	stc->ac = ac;
	stc->av = av;
	stc->env = env;
	stc->cmd = NULL;
	stc->enpath = NULL;
	stc->outfile = -1;
	ft_open_file(stc, INFILE);
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
