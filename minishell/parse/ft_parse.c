#include "../minishell.h"
#include "parse.h"

int tokenizer(t_arg **tmp_line)
{
    check_space(g_data.line, tmp_line);
    return (1);
}

int ft_parse(void)
{
    t_arg   *tmp_line;

    tmp_line = ft_calloc(1, sizeof(t_arg));
    if (!tokenizer(&tmp_line))
        return (-1);
    return (1);
}