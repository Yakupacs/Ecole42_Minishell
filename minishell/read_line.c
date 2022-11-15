/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:44:56 by yacis             #+#    #+#             */
/*   Updated: 2022/11/15 20:47:17 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void	quote_start()
{
	while (1)
	{
		readline("> ");
		signal(SIGINT,handle_int);
	}
}
 */
void	quote_control(t_data *data)
{
	int	i;
	int	sign;
	
	sign = 0;
	i = 0;
	while (data->read1[i])
	{
		if (data->read1[i] == 34)
		{
			sign += 1;
/* 			if (sign % 2 == 0)
			{
				i++;
				buff[j] = data->read1[i];
				
			} */
		}
		i++;
	}
/* 	if (sign % 2 == 1)
		quote_start(); */
}

void	read_line(t_data *data)
{
	data->read1 = readline("\x1B[31mminishell ~ % \x1B[0m");
	quote_control(data);
	data->read2 = ft_split(data->read1, ' ');
	add_history(data->read1);
	if (!(ft_strncmp(data->read1, "", 1)))
		read_line(data);
	else if (!(ft_strncmp(data->read1, "pwd\0", 4)))
		pwd();
	else if (!(ft_strncmp(data->read2[0], "echo", 4)))
		echo(data);
	else if (!(ft_strncmp(data->read1, "env", 3)))
		env_get(data);
	else if (!(ft_strncmp(data->read1, "exit\0", 5)) && \
			ft_strlen2(data->read2) == 1)
		exit(EXIT_FAILURE);
	else if (!(ft_strncmp(data->read2[0], "export ", 7)))
		export(data);
	else
		printf("zsh: command not found: %s\n", data->read1);
}
