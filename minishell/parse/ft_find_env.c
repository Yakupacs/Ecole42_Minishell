#include "../minishell.h"

int	ft_equal_finder(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '=')
		return (1);
	else
		return (0);
}

char	*line_connect(char *arg)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (arg[i] && ft_isalnum(arg[i]))
		i++;
	line = malloc(sizeof(char) * i + 1);
	i = 0;
	while (arg[j] && ft_isalnum(arg[j]))
	{
		line[i] = arg[j];
		i++;
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_find_env2(char *line, char *arg, char *ret, int j)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(line);
	while (g_global.envp[i])
	{
		if (ft_equal_finder(line, g_global.envp[i]) == 1)
		{
			ret = ft_strdup(g_global.envp[i] + len + 1);
			temp = ret;
			ret = ft_strjoin(ret, arg + j);
			free (temp);
			free(arg);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

char	*ft_find_env(char *arg)
{
	int		j;
	char	*line;
	char	*ret;

	j = 0;
	ret = NULL;
	while (arg[j] && ft_isalnum(arg[j]))
		j++;
	line = line_connect(arg);
	free(line);
	ret = ft_find_env2(line, arg, ret, j);
	line = ft_strdup("");
	free(arg);
	if (ret)
		return (ret);
	return (line);
}
