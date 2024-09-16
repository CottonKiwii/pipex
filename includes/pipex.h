/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:50:59 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/16 13:32:28 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>

# define RDERR -1
# define NOSTR NULL

typedef struct	s_cmd
{
	char			*path;
	char			**args;
	struct s_cmd	*next;
}	t_cmd;

typedef struct	s_struct
{
	int				ac;
	char			**av;
	char			**env;
	int				infile;
	int				outfile;
	char			**path;
	t_cmd			*cmd;	
}	t_struct;

void	stc_init(t_struct *stc, int ac, char **av, char **env);
char	*path_init(t_struct *stc);
void	commands_init(t_struct *stc);

void	open_file(t_struct *stc);

void	ft_free_str(char **str);
void	ft_exit(t_struct *stc, int i);

#endif
