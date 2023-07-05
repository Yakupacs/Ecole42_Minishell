#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (ft_strdup(""));
	ft_memcpy(res, s + start, len);
	res[len] = '\0';
	return (res);
}
