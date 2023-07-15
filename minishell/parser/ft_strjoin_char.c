/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 01:40:59 by yacis             #+#    #+#             */
/*   Updated: 2023/07/16 01:42:23 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_char(char const *s1, char c)
{
	size_t	i;
	char	*dizi;

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
