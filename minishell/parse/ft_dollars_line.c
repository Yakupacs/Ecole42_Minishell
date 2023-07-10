#include "../minishell.h"

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
