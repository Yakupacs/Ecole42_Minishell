/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:54 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/15 00:12:43 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	free(str);
	while (variables[i])
	{
		variables[i] = ft_find_env(variables[i]);
		i++;
	}
	str = ft_parse_variables2(variables, str);
	g_global.list->arg = str;
}
