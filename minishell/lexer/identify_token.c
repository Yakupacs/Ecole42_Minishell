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

int initilaze_metacharacter(t_arg *node)
{
	int len;

	len = ft_strlen(node->arg);
	if (len == 1)
	{
		if (*node->arg == '<')
			node->type = INPUT_RDR;
		else if (*node->arg == '>')
			node->type = OUTPUT_RDR;
		else if (*node->arg == '|')
			node->type = PIPE;
	}
	if (len == 2)
	{
		if (*node->arg == '<' && *(node->arg + 1) == '<')
			node->type = DOUBLE_INPUT_RDR;
		else if (*node->arg == '>' && *(node->arg + 1) == '>')
			node->type = DOUBLE_OUTPUT_RDR;
		else
		{
			g_data.error_flag = -2;
			return (-2);
		}
	}
	return (0);
}

int identify_token(t_arg **prompt)
{
	t_arg *iter;

	iter = *prompt;
	while (iter)
	{
		if (contains_dollars(iter->arg))
			iter->type = DOLLAR;
		else if (is_redirection(iter->arg) || is_pipe(iter->arg))
		{
			if (initilaze_metacharacter(iter) == -2)
			{
				g_data.list = *prompt;
				return (0);
			}
		}
		else
			iter->type = WORD;
		iter = iter->next;
	}
	return (1);
}
