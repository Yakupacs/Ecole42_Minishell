#include "../minishell.h"
#include "../parse/parse.h"

int	check_quotation(char *s)
{
	char	handle;
	int		i;
	int		len;

	handle = '\"';
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == handle)
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

int	calculate_new_arg_len(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			while (s[++i] != '\"')
				len++;
		else if (s[i] == '\'')
			while (s[++i] != '\'')
				len++;
		else
			len++;
		i++;
	}
	return (len);
}

char	*trim_quot2(char *s, char *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			while (s[++i] != '\"')
				new[j++] = s[i];
		else if (s[i] == '\'')
			while (s[++i] != '\'')
				new[j++] = s[i];
		else
			new[j++] = s[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}

char	*trim_quot(char *s)
{
	int		len;
	char	*new;

	len = calculate_new_arg_len(s);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new = trim_quot2(s, new);
	return (new);
}

int	contains_quot(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_quotation(&s[i]))
			return (1);
		i++;
	}
	return (0);
}