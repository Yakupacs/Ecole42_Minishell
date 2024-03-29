/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:13 by yacis             #+#    #+#             */
/*   Updated: 2023/07/21 11:45:23 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo_param_checker(char *str)
{
	int	i;

	i = 2;
	if (!str[0] || str[0] != '-')
		return (0);
	if (!str[1] || str[1] != 'n')
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_echo(void)
{
	int	i;

	i = 1;
	if (g_global.command[i] == NULL)
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	while (ft_echo_param_checker(g_global.command[i]) == 1)
		i++;
	while (g_global.command[i])
	{
		ft_putstr_fd(g_global.command[i], 1);
		if (g_global.command[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (ft_echo_param_checker(g_global.command[1]) == 0)
		ft_putstr_fd("\n", 1);
}
