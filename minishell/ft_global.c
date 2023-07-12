#include "minishell.h"

void	ft_init_global(char **envp, int flag)
{
	if (flag)
	{
		g_global.ex_path = copy_env(envp);
		g_global.envp = copy_env(envp);
	}
	g_global.signal_status = 0;
	g_global.list = NULL;
	g_global.command = NULL;
	g_global.redirection = NULL;
	g_global.count_type = NULL;
	g_global.heredoc = NULL;
	g_global.line = NULL;
	g_global.sig_flag = 0;
	g_global.error_flag = 0;
	g_global.here_fd = 0;
}