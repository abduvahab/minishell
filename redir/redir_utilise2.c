/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utilise2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:45:05 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 14:42:05 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*check_out_redir_str(char *s, int ap)
{
	char	*tem;
	int		fd;

	tem = rm_quot_dollar(s);
	free(s);
	if (ap == 1)
	{
		fd = open(tem, O_WRONLY \
			| O_CREAT | O_APPEND, 0666);
		if (fd == -1)
			return (NULL);
	}
	else
	{
		fd = open(tem, O_WRONLY | O_CREAT, 0666);
		if (fd == -1)
			return (NULL);
	}
	close(fd);
	return (tem);
}

int	ft_write_out(char *s, char **r_r, int *n, t_cmd *cmds)
{
	int		i;
	int		st;

	i = 0;
	if (s[++i] == '>')
	{
		cmds->o_ap = 1;
		i++;
	}
	else
		cmds->o_ap = 0;
	st = i;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i])
	{
		i = pass_quotes(s, i);
		if (!s[i] || s[i] == ' ' || s[i] == '>' || s[i] == '<' || s[i] == '\t')
			break ;
		i++;
	}
	if ((*n) >= 1)
		r_r[--(*n)] = check_out_redir_str(ft_substr(s, st, i - st), cmds->i_ap);
	return (i);
}

int	set_infile_cmds(char **l_r, int i, t_cmd *cmds)
{
	extern t_minish	g_minish;

	if (!l_r[i])
	{
		printf("enter a valid filename\n");
		g_minish.statu = 1;
		return (1);
	}
	if (access(l_r[i], F_OK) != 0)
	{
		printf("%s :enter a valid filename\n", l_r[i]);
		free(l_r[i]);
		g_minish.statu = 1;
		return (1);
	}
	if (i == 0)
		cmds->infile = ft_strdup(l_r[i]);
	return (0);
}

int	set_outfile_cmds(char **r_r, int i, t_cmd *cmds)
{
	extern t_minish	g_minish;

	if (!r_r[i])
	{
		printf("open not success\n");
		ft_frees(r_r);
		g_minish.statu = 1;
		return (1);
	}
	if (i == 0)
		cmds->outfile = ft_strdup(r_r[i]);
	return (0);
}

char	*get_here_doc(char *s)
{
	char	buf[2];
	char	*line;
	char	*final;

	line = ft_strdup("");
	final = line;
	write(1, "> ", 1);
	while (1)
	{
		read(0, buf, 1);
		buf[1] = '\0';
		line = ft_strjoin(line, buf);
		if (ft_strchr(line, '\n'))
		{
			if (!ft_strcmp(line, s))
				break ;
			write(1, "> ", 1);
			final = ft_strjoin(final, line);
			free(line);
			line = ft_strdup("");
		}
	}
	free(line);
	return (final);
}
