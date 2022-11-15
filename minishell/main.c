/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:11:29 by yacis             #+#    #+#             */
/*   Updated: 2022/11/15 20:05:46 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	data->ac = ac;
	data->av = av;
	env_create(data, env);
	while (1)
	{
		read_line(data);
		free(data->read1);
	}
}
