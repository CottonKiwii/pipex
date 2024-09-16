/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:29:33 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/16 12:54:45 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	commands_init(t_struct *stc)
{
	int	i;
	t_cmd	*node;

	i = 2;
	while (i < (stc->ac - 1))
	{
		node = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
		if (!node)
			ft_exit(stc, 1);
		node->name = stc->av[i];
		if (i == 2)
			stc->cmd = node;
		node->args = NOSTR;
		node = node->next;
		i++;
	}
}

void	stc_init(t_struct *stc, int ac, char **av, char **env)
{
	stc->ac = ac;	
	stc->av = av;
	stc->env = env;
	commands_init(stc);
	open_file(stc);
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

