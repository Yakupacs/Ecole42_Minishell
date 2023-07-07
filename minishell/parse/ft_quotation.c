#include "../minishell.h"
#include "parse.h"

int check_double_quote(char *line)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (line[i])
    {
        if (line[i] == '\"') // " 
            len++;
        i++;
    }
    if (len % 2)
    {
        g_data.error_flag = -1;
        return (-1);
    }
    else
        return (len);
}

int	check_single_quote(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i]) // echo 'a"a'
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
    if (count % 2 != 0){
        printf("count: %d\n", count);
        g_data.error_flag = -1;
        return (-1);
    }
	return (count);
}
