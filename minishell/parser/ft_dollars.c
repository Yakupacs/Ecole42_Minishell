/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:47 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/20 18:38:31 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_special_func(int j)
{
	int		i;
	char	*tmp;

	i = 0;
	if (j == 0)
		ft_putstr_fd("minishell: ", 1);
	while (g_global.list->arg[i]) 
	{
		if (g_global.list->arg[i] == '$')
		{
			if (g_global.list->arg[i + 1] == '?')
			{
				tmp = ft_itoa(g_global.exit_status);
				ft_putstr_fd(tmp, 1);
				free(tmp);
				i += 2;
			}
			else
				ft_putchar_fd(g_global.list->arg[i++], 1);
		}
		else
			ft_putchar_fd(g_global.list->arg[i++], 1);
	}
	if (j == 0)
		ft_putstr_fd(": command not found\n", 1);
}

int	special_dollar(int i, char *prev_arg)
{
	if (i > 0 && !ft_strcmp(prev_arg, "echo")
			&& !ft_strcmp(prev_arg, "export"))
		return (0);
	if (g_global.list->arg[1] == '?')
	{
		if (ft_strlen(g_global.list->arg) > 2)
		{
			ft_special_func(i);
			free(g_global.list->arg);
			g_global.dollar_flag = 1;
			g_global.list->arg = ft_strdup("");
		}
		else
		{
			free(g_global.list->arg);
			g_global.list->arg = ft_itoa(g_global.exit_status);
		}
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
	int			i;

	i = 0;
	tmp = g_global.list;
	while (g_global.list)
	{
		if (g_global.list->type == DOLLAR)
		{
			flag = quote_parse(g_global.list->arg);
			dollar_parse(g_global.list->arg);
			g_global.list->type = WORD;
			if (flag != -1 && ft_strlen(g_global.list->arg) > 1)
			{
				if (special_dollar(i, tmp->arg) == -1)
					ft_parse_variables();
			}
		}
		g_global.list = g_global.list->next;
		i++;
	}
	g_global.list = tmp;
}
