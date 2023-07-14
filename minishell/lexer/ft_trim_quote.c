/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:06:38 by ikayacio          #+#    #+#             */
/*   Updated: 2023/07/15 00:06:39 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parser/parse.h"

int	calculate_new_arg_len(char *str)
{
	int	i;
	int	arg_len;

	i = 0;
	arg_len = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			while (str[++i] != '\"')
				arg_len++;
		else if (str[i] == '\'')
			while (str[++i] != '\'')
				arg_len++;
		else
			arg_len++;
		i++;
	}
	return (arg_len);
}

char	*trim_quot2(char *str, char *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			while (str[++i] != '\"')
				new[j++] = str[i];
		else if (str[i] == '\'')
			while (str[++i] != '\'')
				new[j++] = str[i];
		else
			new[j++] = str[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}

char	*trim_quot(char *str)
{
	int		len;
	char	*new;

	len = calculate_new_arg_len(str);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new = trim_quot2(str, new);
	return (new);
}

int	contains_quot(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_quotation(&str[i]))
			return (1);
		i++;
	}
	return (0);
}
