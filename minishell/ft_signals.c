#include "minishell.h"

void	signal_exit(void)
{
	write(1, "\033[2D", 4);
	write(1, "\033[0mexit\n", 9);
	exit(0);
}

/* '\00' -> Escape karakteri, '[A' -> Cursor Up, imleci yukarı taşır. */
/* Standart girişe \n karakterini gönderir  */
/* TIOCSTI "Terminal input characters in string" */
void	ft_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		(void)sig;
		g_global.signal_status = -1;
		g_global.exit_status = 1;
		g_global.sig_flag = 1;
		write(1, "\033[A", 3); // 
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
}
