#include "../minishell.h"

void	exec_redir2(int status, char **redir, int i)
{
	if (ft_strcmp(redir[i], "<"))
	{
		g_global.fd = open(redir[i + 1], O_RDONLY, 0644);
		dup2(g_global.fd, 0);
		if (g_global.command && !redir[i + 2])
			exec_shell(status);
		close(g_global.fd);
	}
	else if (ft_strcmp(redir[i], ">>"))
	{
		g_global.fd = open(redir[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		dup2(g_global.fd, 1);
		if (g_global.command[0] && !redir[i + 2]
			&& !ft_strcmp(g_global.command[0], "echo"))
			exec_shell(status);
		close(g_global.fd);
	}
}

void	exec_redir(int status)
{
	char	**redir;
	int		i;

	redir = g_global.redirection;
	i = 0;
	while (redir[i])
	{
		if (ft_strcmp(redir[i], ">"))
		{
			g_global.fd = open(redir[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			dup2(g_global.fd, 1);
			if (g_global.command && !redir[i + 2]
				&& !ft_strcmp(g_global.command[0], "echo"))
				exec_shell(status);
			close(g_global.fd);
		}
		else
			exec_redir2(status, redir, i);
		if (g_global.fd == -1)
		{
			perror("minishell");
			exit(1);
		}
		i += 2;
	}
}
