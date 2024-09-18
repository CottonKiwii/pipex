/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:36:13 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/18 11:08:17 by jwolfram         ###   ########.fr       */
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
		ft_free_str(cur->args);
		free(cur->path);
		free(cur);
		cur = tmp;
	}
}

void	ft_exit(t_struct *stc, int error)
{
	if (errno)
		perror("pipex");
	ft_free_commands(stc);
	ft_free_str(stc->enpath);
	if (stc->infile != RDERR)
		close(stc->infile);
	if (stc->outfile != RDERR)
		close(stc->outfile);
	if (error)
		exit(1);
	exit(0);
}
