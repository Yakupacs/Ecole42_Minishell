#include "../minishell.h"

int	control_bin2(char *path, int j)
{
	char	*dir;
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (path[i])
	{
		j = i;
		while (path[j] && path[j] != ':')
			j++;
		dir = ft_substr(path, i, j - i);
		tmp = ft_strjoin(dir, "/");
		tmp = ft_strjoin(tmp, g_global.command[0]);
		if (access(tmp, F_OK) == 0)
		{
			g_global.command[0] = tmp;
			free(dir);
			return (1);
		}
		free(dir);
		free(tmp);
		i = j + 1;
	}
	return (0);
}

int	control_bin(void)
{
	int		i;
	int		j;
	char	*path;

	j = 0;
	i = 0;
	if (ft_strncmp(g_global.command[0], "./", 2) == 0)
		return (1);
	while (g_global.envp[i])
	{
		if (ft_strncmp(g_global.envp[i], "PATH=", 5) == 0)
		{
			path = g_global.envp[i] + 5;
			break ;
		}
		i++;
	}
	if (g_global.envp[i] == NULL)
		return (1);
	if (control_bin2(path, j))
		return (1);
	return (1);
}

void	ft_execve(void)
{
	if (g_global.command[0][0] == '\0')
	{
		printf("minishell: %s: command not found\n", g_global.command[0]);
		exit(127);
	}
	else if (control_bin())
	{
		if (execve(g_global.command[0], g_global.command, g_global.envp))
		{
			printf("minishell: %s: command not found\n", g_global.command[0]);
/* 			perror("minishell");
 */			exit(127);
		}
	}
}