#include "../minishell.h"

int	equal_counter(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	upenv(char **envp, int j, int flag)
{
	int		l;
	char	*force;

	if (equal_counter(g_global.command[j]) == 0)
		return ;
	force = ft_strdup(g_global.command[j]);
	l = ft_path_founder(envp, g_global.command[j]);
	if (l != -1)
	{
		free(envp[l]);
		if (!flag)
			g_global.envp[l] = force;
		else
			g_global.ex_path[l] = force;
	}
	else
		return ;
}
