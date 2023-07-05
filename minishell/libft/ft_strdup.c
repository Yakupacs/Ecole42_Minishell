#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
