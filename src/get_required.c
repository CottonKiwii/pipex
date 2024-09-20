/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_required.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:56:01 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/20 12:28:56 by jwolfram         ###   ########.fr       */
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

void	ft_null(char **ref)
{
	char	*str;
	
	str = *ref;
	free(str);
	*ref = NULL;
}

int	ft_check_access(t_struct *stc, t_cmd *cur, char *enpath)
{
	char	*path_tmp;

	path_tmp = ft_strdup(enpath);
	if (!path_tmp)
		ft_exit(stc, ERR);
	path_tmp = ft_strjoin(path_tmp, cur->args[0]);
	if (!path_tmp)
		ft_exit(stc, ERR);
	if (!access(path_tmp, X_OK))
	{
		if (cur->path)
			ft_null(&cur->path);
		cur->path = path_tmp;
		return (1);
	}
	if (!access(path_tmp, F_OK))
	{
		if (cur->path)
			ft_null(&cur->path);
		cur->path = path_tmp;
		return (0);
	}
	free(path_tmp);
	return (0);
}

int	default_path(t_struct *stc, t_cmd *cmd)
{
	char	*path_tmp;

	if (ft_strchr(cmd->args[0], '/'))
	{
		cmd->path = ft_strdup(cmd->args[0]);
		if (!cmd->path)
			ft_exit(stc, ERR);
		return (0);
	}
	return (1);
}

void	get_access(t_struct *stc)
{
	t_cmd	*cur;
	int		i;

	cur = stc->cmd;
	while (cur)
	{
		if (!default_path(stc, cur))
		{
			cur = cur->next;
			continue ;
		}
		i = 0;
		while (stc->enpath[i])
		{
			if (ft_check_access(stc, cur, stc->enpath[i]))
				break ;
			i++;
		}
		if (!cur->path)
			cur->path = ft_strdup(cur->args[0]);
		if (!cur->path)
			ft_exit(stc, ERR);
		cur = cur->next;
	}
	errno = 0;
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
