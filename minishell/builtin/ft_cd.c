/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:09 by yacis             #+#    #+#             */
/*   Updated: 2023/07/18 19:37:52 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_oldpwd_changer(void)
{
	char	*str;
	int		i;

	i = 0;
	while (g_global.envp[i])
	{
		if (ft_strncmp(g_global.envp[i], "OLDPWD=", 7) == 0)
		{
			free(g_global.envp[i]);
			str = getcwd(NULL, 0);
			g_global.envp[i] = ft_strjoin("OLDPWD=", str);
			free(str);
			break ;
		}
		i++;
	}
}

void	ft_pwd_changer(void)
{
	char	*str;
	int		i;

	i = 0;
	str = getcwd(NULL, 0);
	while (g_global.envp[i])
	{
		if (ft_strncmp(g_global.envp[i], "PWD=", 4) == 0)
		{
			free(g_global.envp[i]);
			g_global.envp[i] = ft_strjoin("PWD=", str);
			free(str);
			break ;
		}
		i++;
	}
}

void	ft_cd(void)
{
	ft_oldpwd_changer();
	if (g_global.command[1] && ft_strcmp(g_global.command[1], "~") == 0)
	{
		if (chdir(g_global.command[1]))
		{
			g_global.exit_status = 1;
			perror("minishell ");
		}
	}
	else if (chdir(getenv("HOME")))
		perror("minishell ");
	ft_pwd_changer();
}
