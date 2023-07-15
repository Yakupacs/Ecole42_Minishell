/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:47 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/15 21:50:49 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_strjoin2(char const *s1, char c)
{
	size_t i;
	char *dizi;

	i = 0;
	if (!s1 || !c)
		return (NULL);
	dizi = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (dizi == NULL)
		return (NULL);
	while (*s1)
		dizi[i++] = *s1++;
	dizi[i++] = c;
	dizi[i] = '\0';
	return (dizi);
}

void	ft_special_func(void)
{
	int		i;
	char	*tmp;
	char	*str;
	char	*str_temp;

	i = 0;
	while (g_global.list->arg[i]) 
	{
		if (g_global.list->arg[i] == '$')
		{
			if (g_global.list->arg[i + 1] == '?')
			{
				tmp = ft_itoa(g_global.exit_status);
				str_temp = str;
				str = ft_strjoin(str, tmp);
				free(str_temp);
				free(tmp);
				i++;
			}
		}
		else
		{
			if (str)
				str_temp = str;
			str = ft_strjoin2(str, g_global.list->arg[i]);
			free(str_temp);
		}
		i++;
	}
	free(g_global.list->arg);
	g_global.list->arg = ft_strdup(str);
}

int	special_dollar(void)
{
	if (g_global.list->arg[1] == '?')
	{
		if (ft_strlen(g_global.list->arg) > 2)
			ft_special_func();
		else
		{
			free(g_global.list->arg);
			g_global.list->arg = ft_itoa(g_global.exit_status);
		}
		return (0);
	}
	else if (g_global.list->arg[1] == '0')
	{
		free(g_global.list->arg);
		g_global.list->arg = ft_strdup("minishell");
		return (0);
	}
	else if (g_global.list->arg[1] == '$')
	{
		free(g_global.list->arg);
		g_global.list->arg = ft_strdup("4242");
		return (0);
	}
	return (-1);
}

void	dollar_parse(char *str)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != '\"' && str[i] != '\'')
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

int	quote_parse(char *str)
{
	int	i;
	int	single_count;
	int	double_count;

	i = 0;
	single_count = 0;
	double_count = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			double_count++;
		else if (str[i] == '\'')
			single_count++;
		i++;
	}
	if (single_count == 2)
		return (-1);
	else if (double_count == 2)
		return (0);
	else
		return (0);
}

void	ft_dollars(void)
{
	t_command	*tmp;
	int			flag;

	tmp = g_global.list;
	while (g_global.list)
	{
		if (g_global.list->type == DOLLAR)
		{
			flag = quote_parse(g_global.list->arg);
			dollar_parse(g_global.list->arg);
			g_global.list->type = WORD;
			if (flag != -1)
			{
				if (special_dollar() == -1)
					ft_parse_variables();
			}
		}
		g_global.list = g_global.list->next;
	}
	g_global.list = tmp;
}
