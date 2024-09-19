/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_required.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:56:01 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/19 14:40:34 by jwolfram         ###   ########.fr       */
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
		ft_exit(stc, ERR);
	tmp = ft_split(node->path, ' ');
	free(node->path);
	node->path = NULL;
	if (!tmp)
	{
		perror("pipex");
		ft_exit(stc, ERR);
	}
	node->args = tmp;
}

void	get_access(t_struct *stc)
{
	t_cmd	*cur;
	int		i;

	cur = stc->cmd;
	while (cur)
	{
		if (ft_strchr(cur->args[0], '/'))
			return ;
		i = 0;
		while (stc->enpath[i])
		{
			cur->path = ft_strjoin(ft_strdup(stc->enpath[i]), cur->args[0]);
			if (!access(cur->path, X_OK))
				break ;
			errno = 0;
			free(cur->path);
			i++;
		}
		cur = cur->next;
	}
}

void	get_paths(t_struct *stc)
{
	char	*all_paths;
	int		i;

	all_paths = path_init(stc);
	if (!all_paths)
		return ;
	all_paths = ft_substr(all_paths, 5, (ft_strlen(all_paths) - 5));
	if (!all_paths)
		ft_exit(stc, ERR);
	stc->enpath = ft_split(all_paths, ':');
	free(all_paths);
	if (!stc->enpath)
		ft_exit(stc, ERR);
	i = 0;
	stc->enlen = ft_strarrlen(stc->enpath);
	while (stc->enpath[i])
	{
		stc->enpath[i] = ft_strjoin(stc->enpath[i], "/");
		if (!stc->enpath[i])
			ft_exit(stc, ERR);
		i++;
	}
}
