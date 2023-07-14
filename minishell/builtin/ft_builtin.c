/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:03 by yacis             #+#    #+#             */
/*   Updated: 2023/07/15 00:02:04 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin(void)
{
	if (g_global.command == NULL)
		return (-1);
	if (ft_strcmp(g_global.command[0], "cd"))
		ft_cd();
	else if (ft_strcmp(g_global.command[0], "pwd"))
		ft_pwd();
	else if (ft_strcmp(g_global.command[0], "export") && g_global.command[1])
		ft_export();
	else if (ft_strcmp(g_global.command[0], "unset"))
		ft_unset();
	else if (ft_strcmp(g_global.command[0], "env"))
		ft_env();
	else
		return (-1);
	return (0);
}
