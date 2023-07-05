#include "minishell.h"

extern t_data g_data;

void	ft_struct_initilaize(char **envp, int flag)
{
	if (flag)
	{
		g_data.ex_path = copy_env(envp);
		g_data.envp = copy_env(envp);
	}
	g_data.signal_status = 0;
/* 	g_data.list = NULL;
 */	g_data.command = NULL;
	g_data.redirection = NULL;
/* 	g_data.count_type = NULL;
 */	g_data.heredoc = NULL;
	g_data.line = NULL;
	g_data.sig_flag = 0;
	g_data.error_flag = 0;
	g_data.here_fd = 0;
}

void	ft_sig_handler(int sig) // Ctrl + C
{
	if (sig == SIGINT)
	{
		(void)sig;
		g_data.signal_status = -1;
		g_data.exit_status = 1;
		g_data.sig_flag = 1;
		write(1, "\033[A", 3); // '\00' -> Escape karakteri, '[A' -> Cursor Up, imleci yukarı taşır.
		ioctl(STDIN_FILENO, TIOCSTI, "\n"); // Standart girişe \n karakterini gönderir, TIOCSTI "Terminal input characters in string"
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
    return (0);
}