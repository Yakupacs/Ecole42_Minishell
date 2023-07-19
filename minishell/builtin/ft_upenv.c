/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:26 by yacis             #+#    #+#             */
/*   Updated: 2023/07/19 01:39:54 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	equal_counter(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_env(char	*check)
{
	int	i;

	i = 0;
	if (check[0] == '$')
	{
		while (g_global.envp[i])
		{
			if (ft_strcmp(&check[1], g_global.envp[i]))
				return (1);
		}
	}

	return (0);
}

void	upenv(char **envp, int j, int flag)
{
	int		l;
	char	*force;

	if (equal_counter(g_global.command[j]) == 0)
		return ;
	if (ft_check_env(g_global.command[1]))
		force = ft_strdup("hehe");
	else
		force = ft_strdup(g_global.command[j]);
	l = ft_path_founder(envp, g_global.command[j]);
	if (l != -1)
	{
		free(envp[l]);
		if (!flag)
			g_global.envp[l] = force;
		else
			g_global.ex_path[l] = force;
		g_global.exit_status = 0;
	}
	else
		return ;
}
