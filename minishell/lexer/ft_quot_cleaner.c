#include "../minishell.h"
#include "../parse/parse.h"

void	quot_cleaner(t_command **token)
{
	t_command	*node;
	char	*s;

	node = *token;
	while (node)
	{
		if (contains_quot(node->arg))
		{
			if (node->type != DOLLAR)
			{
				s = node->arg;
				node->arg = trim_quot(node->arg);
				free(s);
			}
		}
		node = node->next;
	}
}
