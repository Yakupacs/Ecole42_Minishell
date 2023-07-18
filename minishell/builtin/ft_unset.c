/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:24 by yacis             #+#    #+#             */
/*   Updated: 2023/07/18 19:46:14 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_founder(char *envp, char *name, int len)
{
	int	i;

	i = 0;
	while (envp[i] == name[i] && i < len)
		i++;
	if (envp[i] == '=' || envp[i] == '\0')
		return (1);
	else
		return (0);
}

int	ft_path_counter(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

int	ft_path_founder(char **envp, char *name)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (env_founder(envp[i], name, ft_path_counter(name)) == 1)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_unset(void)
{
	int	i;
	int	j;
	int	l;

	j = 1;
	if (g_global.command[j] == NULL)
		return ;
	while (g_global.command[j])
	{
		i = ft_path_founder(g_global.envp, g_global.command[j]);
		l = ft_path_founder(g_global.ex_path, g_global.command[j]);
		if (i != -1)
			ft_delenv(g_global.envp, i, 0);
		if (l != -1)
			ft_delenv(g_global.ex_path, l, 1);
		j++;
	}
	g_global.exit_status = 0;
}
