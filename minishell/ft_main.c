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

int	continue_loop(t_command *temp)
{
	if (check_error() == -1)
	{
		temp = NULL;
		return (-1);
	}
	printf("\n--\n%s\n--\n", temp[0].arg);
	return (0);
}

void	loop(void)
{
	t_command	*cpy_g_global_list;

	while (1)
	{
		ft_init_global(g_global.envp, 0);
		g_global.line = readline("minishell$ ");
		if (g_global.sig_flag == 1) // Ctrl + C
		{
			free(g_global.line);
			continue ;
		}
		if (!g_global.line) // Ctrl + D
			signal_exit();
		ft_parse();
		cpy_g_global_list = g_global.list;
		/*printf("Arguments:\n");
		int i = 0;
		while (g_global.list){
			printf("%d.arg: %s, type: %u\n", i + 1, g_global.list->arg, g_global.list->type);
			g_global.list = g_global.list->next;
			i++;
		}*/
		add_history(g_global.line);
		free(g_global.line);
		continue_loop(cpy_g_global_list);
		freeliazer(cpy_g_global_list);
	}
}

/*  SIGINT: Ctrl + C */
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