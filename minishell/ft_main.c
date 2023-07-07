#include "minishell.h"

extern t_data g_data;

void ft_struct_initilaize(char **envp, int flag)
{
	if (flag)
	{
		g_data.ex_path = copy_env(envp);
		g_data.envp = copy_env(envp);
	}
	g_data.signal_status = 0;
	g_data.list = NULL;
	g_data.command = NULL;
	g_data.redirection = NULL;
	g_data.count_type = NULL;
	g_data.heredoc = NULL;
	g_data.line = NULL;
	g_data.sig_flag = 0;
	g_data.error_flag = 0;
	g_data.here_fd = 0;
}

int after_loop(t_arg *temp)
{
	printf("after loop temp->content: %s\n", temp->arg);
	return 0;
}

void loop(void)
{
	//t_arg	*cpy_g_data_list;

	while (1)
	{
		ft_struct_initilaize(g_data.envp, 0);
		g_data.line = readline("minishell$ ");
		if (g_data.sig_flag == 1) // NULL Enter
		{
			free(g_data.line);
			continue;
		}
		if (!g_data.line) // Ctrl + D
			signal_exit();
		ft_parse();
		//cpy_g_data_list = g_data.list;
		//add_history(g_data.line);
		//free(g_data.line);
		//after_loop(cpy_g_data_list);
		//freeliazer(cpy_g_data_list);
	}
}

int main(int ac, char **av, char **envp)
{
	if (ac > 1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
	av = NULL;
	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, SIG_IGN);
	g_data.exit_status = 1;
	ft_struct_initilaize(envp, 1);
	loop();
	return (0);
}