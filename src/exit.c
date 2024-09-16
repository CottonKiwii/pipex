/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:36:13 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/16 16:36:17 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_commands(t_struct *stc)
{
	t_cmd	*tmp;		
	t_cmd	*cur;

	cur = stc->cmd;
	while(cur)
	{
		tmp = cur->next;	
		free(cur->path);
		ft_free_str(cur->args);
		free(cur);
		cur = tmp;
	}
}

void	ft_exit(t_struct *stc, int i)
{
	ft_free_commands(stc);
	if (stc->infile)
		close(stc->infile);
	if (stc->outfile)
		close(stc->outfile);
	if (i)
		exit(1);
	exit(0);
}
