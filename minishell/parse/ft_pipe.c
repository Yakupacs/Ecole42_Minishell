#include "../minishell.h"
#include "parse.h"

int	is_pipe(char *s)
{
	if (*s == '|')
		return (1);
	return (0);
}

void	check_pipe(t_command **prompt)
{
	t_command	*iter;

	iter = *prompt;
	while (iter)
	{
		if (handle_character(&iter, &is_pipe))
			iter = iter->next;
		else
			iter = iter->next;
		if (!iter)
			break ;
		if (!iter->next)
		{
			handle_character(&iter, &is_pipe);
			iter = iter->next;
		}
	}
}
