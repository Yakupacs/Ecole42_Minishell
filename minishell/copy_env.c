#include "minishell.h"

char	**copy_env(char **envp)
{
	int		i;
	char	**copy_env;

	i = 0;
	while (envp[i])
		i++;
	copy_env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		copy_env[i] = ft_strdup(envp[i]);
		i++;
	}
	copy_env[i] = NULL;
	return (copy_env);
}