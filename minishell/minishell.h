/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:14:55 by yacis             #+#    #+#             */
/*   Updated: 2022/11/16 20:35:17 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_command
{
	char				**full_cmd;
	char				*full_path;
	int					infile;
	int					outfile;
	int					fd[2];
	struct s_command	*next;
	struct s_command	*prev;
	t_infile			*infile_list;
	t_outfile			*outfile_list;
	t_here_doc			*here_doc_list;
	t_append			*append_list;
	int					pid;
	int					is_only_redir;
}				t_command;

typedef struct s_prompt
{
	t_command	*cmds;
	char		**path;
}				t_prompt;

char		**lexer(char *line);

#endif