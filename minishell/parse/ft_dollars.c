#include "../minishell.h"

/* Burada $$, $? ve $0 gibi özel dolarlar işlenir. */
int special_dollar(void)
{
	if (g_global.list->arg[1] == '?')
	{
		free(g_global.list->arg);
		g_global.list->arg = ft_itoa(g_global.exit_status);
		return (0);
	}
	else if (g_global.list->arg[1] == '0')
	{
		free(g_global.list->arg);
		g_global.list->arg = ft_strdup("minishell");
		return (0);
	}
	else if (g_global.list->arg[1] == '$')
	{
		free(g_global.list->arg);
		g_global.list->arg = ft_strdup("4242");
		return (0);
	}
	return (-1);
}

/* "$a" '$a' dışındaki tırnakları siler. */
void dollar_parse(char *str)
{
	int len;
	int i;
	int j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != '\"' && str[i] != '\'')
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

/* Dışındaki tırnaklara göre tek tırnak ise -1 dönüp işlem yapmaz, çift tırnak ise 0 dönüp doları işler. */
int quote_parse(char *str)
{
	int i;
	int single_count;
	int double_count;

	i = 0;
	single_count = 0;
	double_count = 0;
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

void ft_dollars(void)
{
	t_command *tmp;
	int flag;

	tmp = g_global.list;
	while (g_global.list)
	{
		if (g_global.list->type == DOLLAR)
		{
			flag = quote_parse(g_global.list->arg);
			dollar_parse(g_global.list->arg);
			g_global.list->type = WORD;
			if (flag != -1)
			{
				if (special_dollar() == -1)
					ft_parse_variables();
			}
		}
		g_global.list = g_global.list->next;
	}
	g_global.list = tmp;
}
