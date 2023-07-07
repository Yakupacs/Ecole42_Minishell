#include "../minishell.h"
#include "parse.h"

int tokenizer(t_arg **tmp_line)
{
    check_space(g_data.line, tmp_line);
    if (g_data.error_flag)
    {
        g_data.list = *tmp_line;
        return (0);
    }

    check_redirection(tmp_line);
    check_pipe(tmp_line);

    int i = 0;
    while (*tmp_line != NULL){
        printf("%d.arg: %s, type: %u\n", i + 1, (*tmp_line)->arg, (*tmp_line)->type);
        *tmp_line = (*tmp_line)->next;
        i++;
    }

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