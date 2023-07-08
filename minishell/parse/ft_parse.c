#include "../minishell.h"
#include "parse.h"

void	type_counter(t_arg	**prompt)
{
	g_data.count_type = ft_calloc(1, sizeof(t_type_counter));
	while (*prompt)
	{
		if ((*prompt)->type == INPUT_RDR || (*prompt)->type == OUTPUT_RDR
			|| (*prompt)->type == DOUBLE_OUTPUT_RDR)
			g_data.count_type->rdr++;
		else if ((*prompt)->type == DOLLAR)
			g_data.count_type->dollar++;
		else if ((*prompt)->type == WORD)
			g_data.count_type->word++;
		else if ((*prompt)->type == DOUBLE_INPUT_RDR)
			g_data.count_type->heredoc++;
		else if ((*prompt)->type == PIPE)
			g_data.count_type->pipe++;
		(*prompt) = (*prompt)->next;
	}
}

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

int	tokenizer(t_arg **tmp_line)
{
	check_space(g_data.line, tmp_line);
	if (g_data.error_flag)
	{
		g_data.list = *tmp_line;
		return (0);
	}

	check_redirection(tmp_line);
	check_pipe(tmp_line);
	return (1);
}

int	ft_parse(void)
{
	t_arg	*tmp_line;

	tmp_line = ft_calloc(1, sizeof(t_arg));
	if (!tokenizer(&tmp_line))
		return (-1);
	if (!identify_token(&tmp_line))
		return (-1);
	quot_cleaner(&tmp_line);
	g_data.list = tmp_line;
	type_counter(&tmp_line);
	return (1);
}