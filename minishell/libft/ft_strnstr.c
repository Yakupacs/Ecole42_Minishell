/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:27:49 by yacis             #+#    #+#             */
/*   Updated: 2022/11/14 17:05:17 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, int n)
{
	int	hay;
	int	need;

	hay = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[hay] != 0 && hay < n)
	{
		need = 0;
		while (haystack[hay + need] == needle[need]
			&& needle[need] && need + hay < n)
			need++;
		if (need == ft_strlen(needle))
			return ((char *)&haystack[hay]);
		hay++;
	}
	return (NULL);
}
