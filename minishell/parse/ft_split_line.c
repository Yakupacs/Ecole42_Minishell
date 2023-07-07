#include "../minishell.h"
#include "parse.h"

int is_space(char c)
{
	return (c == 32);
}

int	is_quotation(char *s)
{
	if (*s == '\"')
		return (1);
	else if (*s == '\'')
		return (2);
	return (0);
}

void	split_line(char *s, t_arg *line)
{
	int	st;
	int	len;

	st = 0;
	len = 1;

	split_line2(st, len, s, line);
}

void	split_line2(int st, int len, char *line, t_arg *tmp_line) // len = 1, st = 0, line = (echo "ya'kup")
{
	int	i;

	i = -1;
	while (++i || 1)
	{
		if (is_quotation(&line[i]) == 1 && len++)
			while (!(is_quotation(&line[++i]) == 1) && line[i])
				len++;
		else if (is_quotation(&line[i]) == 2 && len++)
			while (!(is_quotation(&line[++i]) == 2) && line[i])
				len++;
		if (is_space(line[i]) || !line[i])
		{
			if (len != 1){
				printf("len: %d\n", len);
                p_lstadd_back(&tmp_line, p_lstnew(0, ft_substr(line, st, len - 1)));
            }
			st = i + 1;
			len = 0;
		}
		if (!line[i])
			break ;
		len++;
	}
	free(line);
}