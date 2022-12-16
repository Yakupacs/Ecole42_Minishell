/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:44:56 by yacis             #+#    #+#             */
/*   Updated: 2022/11/16 20:33:04 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_line(t_data *data)
{
	data->read1 = readline("\x1B[31mminishell ~ % \x1B[0m");
	read_all_lines(data);
	allocating_lines(data);
	add_history(data->read1);
	if (!(ft_strncmp(data->read1, "", 1)))
		read_line(data);
/* 	else if (!(ft_strncmp(data->read2[0], "pwd\0", 4)) && !data->read2[1])
		pwd();
	else if (!(ft_strncmp(data->read2[0], "echo", 4)))
		echo(data); */
	else if (!(ft_strncmp(data->read1, "env", 3)))
		env_get(data);
/* 	else if (!(ft_strncmp(data->read1, "exit\0", 5)) && \
			ft_strlen2(data->read2) == 1)
		exit(EXIT_FAILURE); */
/* 	else if (!(ft_strncmp(data->read2[0], "export ", 7)))
		export(data); */
	else
		printf("zsh: command not found: %s\n", data->read1);
}
