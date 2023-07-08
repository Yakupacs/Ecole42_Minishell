#include "../minishell.h"
#include "parse.h"

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
	t_arg	*tokens;

	tokens = ft_calloc(1, sizeof(t_arg));
	if (!tokenizer(&tokens))
		return (-1);
	if (!identify_token(&tokens))
		return (-1);
	quot_cleaner(&tokens);
	g_data.list = tokens;
	type_counter(&tokens);
	return (1);
}