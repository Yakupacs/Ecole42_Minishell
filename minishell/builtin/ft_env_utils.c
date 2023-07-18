/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:17 by yacis             #+#    #+#             */
/*   Updated: 2023/07/18 20:13:11 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_delenv2(char **new_envp, int flag)
{
	if (!flag)
		g_global.envp = new_envp;
	else
		g_global.ex_path = new_envp;
}

void	ft_delenv(char **envp, int j, int flag)
{
	int		i;
	int		k;
	char	**new_envp;

	k = 0;
	i = 0;
	new_envp = (char **)malloc(sizeof(char *) * (env_counter(envp)));
	while (envp[i])
	{
		if (i == j)
		{
			free(envp[i]);
			i++;
		}
		else
		{
			new_envp[k] = envp[i];
			i++;
			k++;
		}
	}
	new_envp[k] = NULL;
	ft_delenv2(new_envp, flag);
	free(envp);
}

void	ft_addenv(char **envp, int j, int flag)
{
	int		i;
	char	*force;
	char	**new_envp;

	i = 0;
	force = ft_strdup(g_global.command[j]);
	new_envp = (char **)malloc(sizeof(char *) * (env_counter(envp) + 2));
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		free(envp[i]);
		i++;
	}
	new_envp[i] = force;
	new_envp[i + 1] = NULL;
	if (!flag)
		g_global.envp = new_envp;
	else
		g_global.ex_path = new_envp;
	g_global.exit_status = 0;
	free(envp);
}

int	env_counter(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

void	ft_env(void)
{
	int	i;

	i = 0;
	while (g_global.envp[i])
	{
		ft_putstr_fd(g_global.envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	g_global.exit_status = 0;
}
