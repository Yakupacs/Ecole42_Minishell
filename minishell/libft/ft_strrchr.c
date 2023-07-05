#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (*(str + i) == (char)c)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}
