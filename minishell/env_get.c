/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:52:25 by yacis             #+#    #+#             */
/*   Updated: 2022/11/15 13:15:27 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_get(t_data *data)
{
	int	i;

	i = 0;
	if (!(ft_strncmp(data->read2[0], "env\0", 4)) && !data->read2[1])
	{
		while (data->env[i])
		{
			printf("%s\n", data->env[i]);
			i++;
		}
	}
	else
		printf("zsh: command not found: %s\n", data->read1);
}
