/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:11:29 by yacis             #+#    #+#             */
/*   Updated: 2022/11/16 18:56:38 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int loop(char **line, char ***lexed)
{
    *line = readline("minishell$ ");
    add_history(*line);
    *lexed = lexer(*line);
    if (!*lexed)
    {
        free(*line);
        return (1);
    }
    return (0);
}

int	main()
{
    char        **lexed;
    char        *line;
    t_prompt    *parsed;

    line = NULL;
    lexed = NULL;
    while (1)
    {
        if (loop(&line, &lexed))
            continue;
        parsed = parser(lexed);
    }
}
