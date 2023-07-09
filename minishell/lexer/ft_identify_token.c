#include "../minishell.h"
#include "../parse/parse.h"

int	is_dollar(char *str)
{
	int	i;

	i = -1;
	if (!str || !*str)
		return (0);
	while (str[++i])
		if (str[i] == '$')
			return (1);
	return (0);
}

int	identify_token(t_command **prompt)
{
	t_command	*node;

	node = *prompt;
	while (node)
	{
		if (is_dollar(node->arg))
			node->type = DOLLAR;
		else if (is_redirection(node->arg) || is_pipe(node->arg))
		{
			if (initialize_metacharacter(node) == -2)
			{
				g_global.list = *prompt;
				return (0);
			}
		}
		else
			node->type = WORD;
		node = node->next;
	}
	return (1);
}
