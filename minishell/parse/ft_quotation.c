#include "../minishell.h"
#include "parse.h"

int    check_quote(char *line)
{
    int i;
    int sign;
    
    sign = 0;
    i = 0;
    while (line[i])
    {
        if (line[i] == '\''){
            if (sign != 1 && sign != 2)
                sign = 1;
            else if (sign == 1)
                sign = 0;
        }
        else if (line[i] == '\"'){
            if (sign != 1 && sign != 2)
                sign = 2;
            else if (sign == 2)
                sign = 0;
        }
        i++;
    }
    return (sign);
}