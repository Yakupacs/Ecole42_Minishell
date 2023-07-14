#include "minishell.h"

void exec_shell(int status)
{
	if (status == 0)
		ft_execve();
	else
		perror("minishell");
}

int	continue_loop(t_command *cpy_g_global_list)
{
	if (check_error() == -1)
	{
		cpy_g_global_list = NULL;
		return (-1);
	}
	if (g_global.count_type->dollar > 0)
		ft_dollars();
	if (g_global.count_type->heredoc > 0)
		ft_heredoc();
	if (ft_strcmp(g_global.list->arg, "exit"))
	{
		ft_exit(cpy_g_global_list);
		return (-1);
	}
	if (initialize_pipe() == -1)
		execute();
	return (0);
}

void	loop(void)
{
	t_command	*cpy_g_global_list;

	while (1)
	{
		ft_init_global(g_global.envp, 0);
		g_global.line = readline("minishell$ ");
		if (g_global.sig_flag == 1)
		{
			free(g_global.line);
			continue ;
		}
		if (!g_global.line)
			signal_exit();
		ft_lexer();
		cpy_g_global_list = g_global.list;
		add_history(g_global.line);
		free(g_global.line);
		continue_loop(cpy_g_global_list);
		freeliazer(cpy_g_global_list);
	}
}

int	main(int ac, char **av, char **envp)
{
 	(void)ac;
	(void)av;
	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, SIG_IGN);
	g_global.exit_status = 1;
	ft_init_global(envp, 1);
	loop();
	return (0);
}