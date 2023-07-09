#include "../minishell.h"
#include "parse.h"

int	tokenizer(t_command **tmp_line)
{
	check_space(g_global.line, tmp_line);
	if (g_global.error_flag)
	{
		g_global.list = *tmp_line;
		return (0);
	}
	check_redirection(tmp_line);
	check_pipe(tmp_line);
	return (1);
}

int	ft_parse(void)
{
	t_command	*tokens;

	tokens = ft_calloc(1, sizeof(t_command));
	if (!tokenizer(&tokens))
		return (-1);
	if (!identify_token(&tokens))
		return (-1);
	quot_cleaner(&tokens);
	g_global.list = tokens;
	type_counter(&tokens);
	return (1);
}