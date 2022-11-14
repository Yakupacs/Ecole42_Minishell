/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:11:29 by yacis             #+#    #+#             */
/*   Updated: 2022/11/14 21:18:32 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_readline(t_data *data)
{
	data->read1 = readline("\x1B[31mminishell ~ % \x1B[0m");
	data->read2 = ft_split(data->read1, ' ');
	add_history(data->read1);
	if (!(ft_strncmp(data->read1, "pwd", 3)))
		pwd();
	else if (!(ft_strncmp(data->read2[0], "echo", 4)))
		echo(data);
	else if (!(ft_strncmp(data->read1, "env", 3)))
		env_get(data);
	else if (!(ft_strncmp(data->read1, "exit\0", 5)) && ft_strlen2(data->read2) == 1)
		exit(EXIT_FAILURE);
	else if (!(ft_strncmp(data->read2[0], "export ", 7)))
		export(data);
	else
		printf("zsh: command not found: %s\n", data->read1);
	free(data->read1);
}

int main(int ac, char **av, char **env)
{
	t_data *data;

	data = ft_calloc(sizeof(t_data), 1);
	data->ac = ac;
	data->av = av;
	env_create(data, env);
	while (1)
		ft_readline(data);
}
