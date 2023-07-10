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
	char	**line;
	int		i;

	i = 0;
	str = g_global.list->arg;
	line = ft_split(str, '$');
	free(str);
	while (line[i])
	{
		line[i] = ft_find_env(line[i]);
		i++;
	}
	str = ft_parse_dollars2(line, str);
	g_global.list->arg = str;
}