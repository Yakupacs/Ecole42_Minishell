/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:35:17 by yacis             #+#    #+#             */
/*   Updated: 2023/07/19 19:58:41 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_write_export_path(char *tmp)
{
	int	k;

	k = 0;
	ft_putstr_fd("declare -x ", 1);
	while (tmp[k] && tmp[k] != '=')
		ft_putchar_fd(tmp[k++], 1);
	k++;
	ft_putchar_fd('=', 1);
	ft_putchar_fd('\"', 1);
	while (tmp[k])
		ft_putchar_fd(tmp[k++], 1);
	ft_putchar_fd('\"', 1);
	ft_putstr_fd("\n", 1);
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
		ft_write_export_path(tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}
