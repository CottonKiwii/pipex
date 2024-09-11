/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:29:33 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/11 18:32:14 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	stc_init(t_struct *stc, int ac, char **av, char **env)
{
	stc->ac = ac;	
	stc->av = av;
	stc->env = env;
	stc->cmd1 = av[3];	
	stc->cmd2 = av[4];
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

