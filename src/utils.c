/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:18:04 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/16 13:00:00 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_str(char **str)
{
	int	idx;
	int	idx2;

	idx = 0;
	idx2 = 0;
	while (str[idx])
	{

	}
}

void	ft_exit(t_struct *stc, int i)
{
	t_cmd	*tmp;		
	t_cmd	*cur;

	cur = stc->cmd;
	while(cur)
	{
		tmp = cur->next;
		if (cur->args)
			ft_free_str(cur->args);
		free(cur);
		cur = tmp;
	}
	if (i)
		exit(1);
	exit(0);
}
