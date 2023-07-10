#include "../minishell.h"

char	*ft_parse_dollars2(char **line, char *src)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i])
	{
		if (i == 0)
			src = ft_strdup(line[i]);
		else
		{
			temp = src;
			src = ft_strjoin(src, line[i]);
			free(temp);
		}
		free(line[i]);
		i++;
	}
	free(line);
	return (src);
}

void	ft_parse_dollars(void)
{
	char	*str;
	char	**variable;
	int		i;

	i = 0;
	str = g_global.list->arg;
	variable = ft_split(str, '$');
	free(str);
	while (variable[i])
	{
		variable[i] = ft_find_env(variable[i]);
		i++;
	}
	str = ft_parse_dollars2(variable, str);
	g_global.list->arg = str;
}