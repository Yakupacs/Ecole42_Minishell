/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:14:55 by yacis             #+#    #+#             */
/*   Updated: 2022/11/15 19:46:04 by yacis            ###   ########.fr       */
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

/* #define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m" */

typedef struct s_data
{
	int		ac;
	char	**av;
	char	**env;
	char	*read1;
	char	**read2;
}		t_data;

void	echo(t_data *data);
void	env_get(t_data *data);
void	env_create(t_data *data, char **env);
void	export(t_data *data);
void	pwd(void);
void	read_line(t_data *data);
int		ft_strlen2(char **str);

#endif