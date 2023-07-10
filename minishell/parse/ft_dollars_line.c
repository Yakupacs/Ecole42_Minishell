#include "../minishell.h"

int	quot_parse(char *str)
{
	int	i;
	int	double_count;
	int	single_count;

	i = 0;
	double_count = 0;
	single_count = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			double_count++;
		else if (str[i] == '\'')
			single_count++;
		i++;
	}
	if (single_count == 2)
		return (-1);
	else if (double_count == 2)
		return (0);
	else
		return (0);
}

void	ft_dollars_line(void)
{
	t_command	*temp_s;
	int			flag;

	temp_s = g_global.list;
	while (g_global.list)
	{
		if (g_global.list->type == DOLLAR)
		{
			flag = quot_parse(g_global.list->arg);
			dollar_prs(g_global.list->arg);
			g_global.list->type = WORD;
			if (flag != -1)
			{
				if (special_parse() == -1)
					ft_parse_dollars();
			}
		}
		g_global.list = g_global.list->next;
	}
	g_global.list = temp_s;
}
