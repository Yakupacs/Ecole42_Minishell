#include "lexer.h"

int count_double_quotes(char *line)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (line[i])
    {
        if (line[i] == '"')
            count++;
        i++;
    }
    return (count);
}

int count_single_quotes(char *line)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (line[i])
    {
        while (line[i] != '"' && line[i] != '\0')
        {
            if (line[i] == '\'')
                count++;
            i++;
        }
        if (line[i])
            i++;
        while (line[i] != '"' && line[i] != '\0')
            i++;
        if (line[i])
            i++;
    }
    return (count);
}