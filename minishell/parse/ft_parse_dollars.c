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
	char	*src;
	char	**line;
	int		i;

	i = 0;
	src = g_global.list->arg;
	line = ft_split(src, '$');
	free(src);
	while (line[i])
	{
		line[i] = ft_find_env(line[i]);
		i++;
	}
	src = ft_parse_dollars2(line, src);
	g_global.list->arg = src;
}