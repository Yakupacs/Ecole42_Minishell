#include "../minishell.h"
#include "../parse/parse.h"

int	is_dollar(char *str)
{
	int	i;

	i = -1;
	if (!str || !*str)
		return (0);
	while (str[++i])
		if (str[i] == '$' && (str[i + 1] == '?' || str[i + 1] == '0'))
			return (1);
	return (0);
}

int	identify_token(t_command **token)
{
	t_command	*node;

	node = *token;
	while (node)
	{
		if (is_dollar(node->arg))
			node->type = DOLLAR;
		else if (is_redirection(node->arg) || is_pipe(node->arg))
		{
			if (initialize_metacharacter(node) == -2)
			{
				g_global.list = *token;
				return (0);
			}
		}
		else
			node->type = WORD;
		node = node->next;
	}
	return (1);
}
