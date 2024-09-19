/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:50:59 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/19 14:55:08 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

# define RDERR	-1
# define WR O_WRONLY
# define CR O_CREAT
# define TR O_TRUNC

typedef enum	e_nbr
{
	TRUE,
	ERR,
	INFILE,
	OUTFILE
}	t_nbr;

typedef struct	s_cmd
{
	int				nbr;
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
	int				enlen;
	char			**enpath;
	t_cmd			*cmd;	
}	t_struct;

void	node_init(t_struct *stc, t_cmd *node, t_cmd *tmp, int count);
void	commands_init(t_struct *stc);
void	stc_init(t_struct *stc, int ac, char **av, char **env);
char	*path_init(t_struct *stc);

void	ft_open_file(t_struct *stc, t_nbr file);
void	ft_wrap_dup(t_struct *stc, int old_fd, int new_fd);

void	get_args(t_cmd *node, t_struct *stc);
void	get_access(t_struct *stc);
void	get_paths(t_struct *stc);

void	ft_free_str(char **str, int len);
void	ft_free_commands(t_struct *stc);
void	ft_exit(t_struct *stc, int i);

#endif
