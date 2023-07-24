/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:04:58 by yacis             #+#    #+#             */
/*   Updated: 2023/07/24 18:04:46 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigquit(int sig)
{
	(void)sig;
	if (g_global.sigquit_flag == 1)
	{
		printf("Quit: 3\n");
		g_global.sigquit_flag = 0;
	}
}

void	ft_sighandler(int sig)
{
	if (sig == SIGINT && g_global.execute_flag == 0)
	{
		(void)sig;
		g_global.signal_status = -1;
		g_global.exit_status = 1;
		g_global.sig_flag = 1;
		g_global.heredoc_flag = 1;
		write(1, "\033[A", 3);
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
}
