/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:20 by yacis             #+#    #+#             */
/*   Updated: 2023/07/22 19:52:10 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid(int j)
{
	int	i;

	i = 0;
	if (g_global.command[j][0] == '=') 
		return (-1);
	if (ft_isdigit(g_global.command[j][i]) == 1)
		return (-1);
	while (g_global.command[j][i])
	{
		if (g_global.command[j][i] == '=')
			return (0);
		if (ft_isalnum(g_global.command[j][i]) == 0
			&& g_global.command[j][i] != '_')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_env_controller(int j)
{
	int	i;

	i = 0;
	while (g_global.command[j][i] != '\0')
	{
		if (g_global.command[j][i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_export2(int line, int line_exp, int i)
{
	while (g_global.command[i])
	{
		if (is_valid(i) == -1)
		{
			printf("minishell: export: %s : not a valid identifier\n",
				g_global.command[i++]);
			g_global.exit_status = 1;
			continue ;
		}
		line = ft_path_founder(g_global.envp, g_global.command[i]);
		line_exp = ft_path_founder(g_global.ex_path, g_global.command[i]);
		if (line != -1)
			upenv(g_global.envp, i, 0);
		if (line_exp != -1)
			upenv(g_global.ex_path, i, 1);
		if (line == -1 && ft_env_controller(i))
			ft_addenv(g_global.envp, i, 0);
		if (line_exp == -1)
			ft_addenv(g_global.ex_path, i, 1);
		i++;
	}
}

void	ft_export(void)
{
	int	index;
	int	line;
	int	line_exp;

	line = 0;
	line_exp = 0;
	index = 1;
	ft_export2(line, line_exp, index);
}
