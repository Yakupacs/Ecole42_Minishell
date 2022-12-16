/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:49:06 by yacis             #+#    #+#             */
/*   Updated: 2022/11/16 20:35:26 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	space_control(t_data *data, int i)
{
	while (data->read1[i] != 32 && data->read1[i] != 34 && data->read1[i])
		i++;
	if (data->read1[i] == 32)
		i++;
	return (i);
}

int	quote_control(t_data *data, int i)
{
	int quote_len;

	quote_len = 1;
	i++;
	while (data->read1[i] && data->read1[i] != 34)
		i++;
	if (data->read1[i] == 34)
	{
		quote_len += 1;
		i++;		
	}
	if (quote_len == 1)
		exit(EXIT_FAILURE);
	return (i);
}

void	read_all_lines(t_data *data)
{
	int	i;
	int	j;
	int quote_len;

	i = 0;
	j = 0;
	quote_len = 0;
	while (data->read1[i])
	{
		while (data->read1[i] == 32)
			i++;
		if (data->read1[i] == 34 && data->read1[i + 1] != 34){
			quote_len += 1;
			i = quote_control(data, i);
			j++;
		}
		else if (data->read1[i] != 34 && data->read1[i] && data->read1[i] != 32)
		{
			i = space_control(data, i);
			j++;
		}
	}
	data->words_count = j;
}