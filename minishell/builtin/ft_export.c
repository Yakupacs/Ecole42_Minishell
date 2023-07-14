/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:20 by yacis             #+#    #+#             */
/*   Updated: 2023/07/15 00:02:21 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	name_error(int j)
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

void	*ft_export_path(void)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (g_global.ex_path[i])
	{
		j = 0;
		while (g_global.ex_path[i][j])
			j++;
		tmp = ft_substr(g_global.ex_path[i], 0, j);
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp, 1);
		ft_putstr_fd("\n", 1);
		free(tmp);
		i++;
	}
	return (NULL);
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

void	ft_export2(int line, int line_exp, int j)
{
	while (g_global.command[j])
	{
		if (name_error(j) == -1)
		{
			printf("minishell: export: %s : not a valid identifier\n",
				g_global.command[j++]);
			continue ;
		}
		line = ft_path_founder(g_global.envp, g_global.command[j]);
		line_exp = ft_path_founder(g_global.ex_path, g_global.command[j]);
		if (line != -1)
			upenv(g_global.envp, j, 0);
		if (line_exp != -1)
			upenv(g_global.ex_path, j, 1);
		if (line == -1 && ft_env_controller(j))
			ft_addenv(g_global.envp, j, 0);
		if (line_exp == -1)
			ft_addenv(g_global.ex_path, j, 1);
		j++;
	}
}

void	ft_export(void)
{
	int	j;
	int	line;
	int	line_exp;

	line = 0;
	line_exp = 0;
	j = 1;
	ft_export2(line, line_exp, j);
}
