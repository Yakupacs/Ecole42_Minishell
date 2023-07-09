#include "../minishell.h"
#include "../parse/parse.h"

void	type_counter(t_arg	**prompt)
{
	g_global.count_type = ft_calloc(1, sizeof(t_type_counter));
	while (*prompt)
	{
		if ((*prompt)->type == INPUT_RDR || (*prompt)->type == OUTPUT_RDR
			|| (*prompt)->type == DOUBLE_OUTPUT_RDR)
			g_global.count_type->rdr++;
		else if ((*prompt)->type == DOLLAR)
			g_global.count_type->dollar++;
		else if ((*prompt)->type == WORD)
			g_global.count_type->word++;
		else if ((*prompt)->type == DOUBLE_INPUT_RDR)
			g_global.count_type->heredoc++;
		else if ((*prompt)->type == PIPE)
			g_global.count_type->pipe++;
		(*prompt) = (*prompt)->next;
	}
}
