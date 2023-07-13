#include "../minishell.h"

void	check_way(void)
{
	int		status;

	status = 0;
	if (g_global.count_type->heredoc)
	{
		dup2(g_global.here_fd[0], STDIN_FILENO);
		close(g_global.here_fd[0]);
	}
	if (g_global.redirection != NULL)
		exec_redir(status);
	if (ft_strcmp(g_global.command[0], "export"))
	{
		if (g_global.command[1] == NULL)
			ft_export_path();
		else
			ft_export();
		exit(0);
	}
	else if (ft_strcmp(g_global.command[0], "echo"))
	{
		ft_echo();
		exit(0);
	}
	else if (g_global.command != NULL)
		ft_execve();
}

void	execute(void)
{
	int	status;
	int	i;

	i = 0;
	ft_command_line();
	if (builtin() == -1)
		status = fork();
	else
		return ;
	if (status == 0)
		check_way();
	else
		waitpid(status, &g_global.exit_status, 0);
	if (WIFEXITED(g_global.exit_status) && i == 0)
	{
		g_global.exit_status = WEXITSTATUS(g_global.exit_status);
		i++;
	}
}