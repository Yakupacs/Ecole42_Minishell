#include "minishell.h"

void	signal_exit(void)
{
	write(1, "\033[2D", 4);
	write(1, "\033[0mexit\n", 9);
	exit(0);
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
