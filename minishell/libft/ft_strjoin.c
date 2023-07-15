/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:04:04 by yacis             #+#    #+#             */
/*   Updated: 2023/07/15 21:11:44 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*dizi;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	dizi = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dizi == NULL)
		return (NULL);
	while (*s1)
		dizi[i++] = *s1++;
	while (*s2)
		dizi[i++] = *s2++;
	dizi[i] = '\0';
	return (dizi);
}
