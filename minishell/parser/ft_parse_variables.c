/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:54 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/17 02:42:11 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_str2len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_parse_variables2(char **line, char *src)
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

void	ft_parse_variables(void)
{
	char	*str;
	char	**variables;
	int		i;

	i = 0;
	str = g_global.list->arg;
	variables = ft_split(str, '$');
	if (ft_str2len(variables) == 0)
	{
		free(variables);
		return ;
	}
	free(str);
	while (variables[i]) 
	{
		variables[i] = ft_find_env(variables[i]);
		i++;
	}
	str = ft_parse_variables2(variables, str);
	g_global.list->arg = str;
}
