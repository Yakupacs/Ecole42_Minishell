/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:57:44 by yacis             #+#    #+#             */
/*   Updated: 2022/11/15 12:58:33 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	env_create(t_data *data, char **env)
{
	int		i;
	int		j;
	char	**envv;

	i = 0;
	envv = malloc(sizeof(char *) * ft_strlen2(env) + 1);
	while (env[i])
	{
		j = 0;
		envv[i] = malloc(sizeof(char) * ft_strlen(env[i]) + 1);
		while (env[i][j])
		{
			envv[i][j] = env[i][j];
			j++;
		}
		i++;
	}
	data->env = envv;
}
