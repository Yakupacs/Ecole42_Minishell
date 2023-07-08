#include "../minishell.h"
#include "../parse/parse.h"

void	quot_cleaner(t_arg **prompt)
{
	t_arg	*iter;
	char	*s;

	iter = *prompt;
	while (iter)
	{
		if (contains_quot(iter->arg))
		{
			if (iter->type != DOLLAR)
			{
				s = iter->arg;
				iter->arg = trim_quot(iter->arg);
				free(s);
			}
		}
		iter = iter->next;
	}
}
