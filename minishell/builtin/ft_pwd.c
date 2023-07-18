/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:02:22 by yacis             #+#    #+#             */
/*   Updated: 2023/07/18 19:43:44 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	g_global.exit_status = 0;
	free(path);
}
