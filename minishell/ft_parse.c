#include "minishell.h"

int tokenizer(t_arg **prompt)
{
    printf("%s\n", prompt[0]->content);
    return (1);
}

int ft_parse(void)
{
    t_arg   *line;

    line = ft_calloc(1, sizeof(t_arg));
    if (!tokenizer(&line))
		return (-1);
    return (1);
}