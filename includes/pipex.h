/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:50:59 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/11 18:32:42 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>

typedef struct	s_struct
{
	int		ac;
	char	**av;
	char	**env;
	int		infile;
	int		outfile;
	char	*cmd1;
	char	*cmd2;
	char	**path;
}	t_struct;

void	stc_init(t_struct *stc, int ac, char **av, char **env);
char	*path_init(t_struct *stc);

void	open_file(t_struct *stc);

#endif
