/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:20:47 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 17:03:55 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pc_pipe(char *line)
{
	int		i;
	char	**check;

	i = 0;
	check = ft_split(line, ' ');
	while (check[i + 1])
	{
		if ((ft_strncmp(check[i], "|", 1)) == 0
			&& (ft_strncmp(check[i + 1], "|", 1) == 0))
		{
			ft_putstr_fd("Error: Incorrect syntax for pipes\n", 2);
			ft_frees(check);
			return (2);
		}
		i++;
	}
	ft_frees(check);
	return (0);
}

int	pc_end(char *line)
{
	int	len;

	len = ft_strlen(line) - 1;
	while (ft_isspace(line[len]))
		len--;
	if (line[0] == '|')
	{
		printf("First character must not be a pipe or redirection symbol.\n");
		return (1);
	}
	else if (line[len] == '>' || line[len] == '<')
	{
		printf("Error: Last character must not be a redirection symbol.\n");
		return (1);
	}
	return (0);
}

int	pc_chars(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && !q)
			q = str[i];
		else if (q && str[i] == q)
			q = 0;
		else if (!q && (str[i] == '\\' || str[i] == ';' || str[i] == '&'
				|| str[i] == '!' || str[i] == '`' || str[i] == '('
				|| str[i] == ')' || str[i] == '#' || str[i] == '*'))
		{
			printf(" Error :%c is a forbidden character.\n", str[i]);
			return (1);
		}
				i++;
	}
	return (0);
}

int	quotes_is_closed(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && !q)
			q = str[i];
		else if (q && str[i] == q)
			q = 0;
		i++;
	}
	if (!q)
		return (0);
	printf("Error: Unclosed quote detected.\n");
	return (1);
}

int	check_line(char *line)
{
	extern t_minish	g_minish;
	char			*tem;

	if (!line || line[0] == '\0')
		return (0);
	if (ft_arespaces(line))
		return (0);
	tem = ft_strtrim(line, " \t");
	if (quotes_is_closed(tem) || pc_chars(tem) || pc_redirs(tem)
		|| pc_end(tem) || pc_pipe(tem))
	{
		g_minish.statu = 2;
		free(tem);
		return (0);
	}
	free(tem);
	return (1);
}
