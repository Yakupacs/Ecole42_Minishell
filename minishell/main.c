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
    
}

int	main()
{
    char    **lexed;
    char    *line;

    line = NULL;
    lexed = NULL;
    while (1)
    {
        if (loop(&line, &lexed))
            continue;
    }
}
