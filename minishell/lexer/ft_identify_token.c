#include "../minishell.h"
#include "../parse/parse.h"

int identify_token(t_arg **prompt)
{
	t_arg *iter;

	iter = *prompt;
	printf("a\n");
	while (iter)
	{
		printf("b\n");
		if (contains_dollars(iter->arg))
			iter->type = DOLLAR;
		else if (is_redirection(iter->arg) || is_pipe(iter->arg))
		{
			if (initialize_metacharacter(iter) == -2)
			{
				g_data.list = *prompt;
				return (0);
			}
		}
		else
			iter->type = WORD;
		iter = iter->next;
		printf("c\n");
	}
	return (1);
}
