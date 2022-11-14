/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:02:01 by yacis             #+#    #+#             */
/*   Updated: 2022/11/14 20:47:23 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_n_control(char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[0] == '-' && str[1] == 'n')
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo(t_data *data)
{
	int	i;

	if (!(ft_strncmp(data->read2[1], "-n", 2)) && \
			ft_n_control(data->read2[1]))
	{
		i = 2;
		while (data->read2[i])
		{
			printf("%s", data->read2[i]);
			i++;
		}
	}
	else
	{
		i = 1;
		while (data->read2[i])
		{
			printf("%s", data->read2[i]);
			if (data->read2[i + 1])
				printf(" ");
			i++;
		}
		printf("\n");
	}
}
