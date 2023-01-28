/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:50:27 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 13:40:26 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_with_optin(char *s, int fd)
{
	char			**tem;
	char			*tem2;
	int				i;
	int				n;

	tem = ft_split(s, ' ');
	i = 0;
	i = find_echo_str(tem, i);
	n = i;
	if (!tem[i])
		return ;
	tem2 = ft_strnstr(s, tem[i], ft_strlen(s));
	if (n > 0)
		write_str_echo(tem2, 0, fd);
	else
		write_str_echo(tem2, 1, fd);
	ft_frees(tem);
}

int	number_strs(char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			i = pass_quotes(s, i);
		else
		{
			if (s[i] == ' ')
			{
				n++;
				while (s[i] && (s[i] == ' '))
					i++;
			}
			else
				i++;
		}
	}
	return (n);
}

char	**rm_space_echo(char *s, char **str)
{
	int				i;
	int				j;
	int				d;

	i = -1;
	j = 0;
	d = 0;
	while (s[++i])
	{
		if (s[i] == '\"' || s[i] == '\'')
			i = pass_quotes(s, i) - 1;
		else
		{
			if (s[i] && s[i] == ' ')
			{
				str[j++] = ft_substr(s, d, i - d);
				while (s[i] && s[i] == ' ')
					i++;
				d = (i--);
			}
		}
	}
	str[j++] = ft_substr(s, d, i - d);
	str[j] = NULL;
	return (str);
}

void	write_str_echo(char *s, int m, int fd)
{
	extern t_minish	g_minish;
	char			*str;
	char			**strs;
	char			*tem;
	int				n;

	n = number_strs(s);
	str = s;
	if (n > 0)
	{
		strs = malloc(sizeof(char *) * (n + 2));
		if (!str)
			return ;
		rm_space_echo(s, strs);
		str = ft_echo_joins(strs);
		ft_frees(strs);
	}
	tem = rm_quot_dollar(str);
	ft_putstr_fd(tem, fd);
	free(tem);
	if (n > 0)
		free(str);
	if (m)
		ft_putstr_fd("\n", fd);
}

void	exec_echo(t_cmd *cmds)
{
	extern t_minish	g_minish;
	char			*tem;
	char			*line;
	char			*home;

	line = cmds->p_line;
	if (!ft_strcmp(line, "echo"))
	{
		write(1, "\n", 1);
		return ;
	}
	else
	{
		tem = line + 4;
		tem = ft_substr(tem, 0, ft_strlen(tem));
		home = ft_strtrim(tem, " ");
		free(tem);
		if (home && home[0] == '-')
			echo_with_optin(home, 1);
		else
			write_str_echo(home, 1, 1);
		free(home);
	}
}
