#include "../minishell.h"
#include "../parse/parse.h"

int contains_dollars(char *str)
{
	int i;

	i = -1;
	if (!str || !*str)
		return (0);
	while (str[++i])
		if (str[i] == '$')
			return (1);
	return (0);
}
