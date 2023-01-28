/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utilise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:41:47 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 11:01:20 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_redir_strs(char *s, char *final)
{
	char	*line;
	int		fd;

	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		return (NULL);
	line = ft_strjoin2(s, "\n");
	final = get_here_doc(line);
	ft_putstr_fd(final, fd);
	free(final);
	close(fd);
	free(line);
	return (ft_strdup(".heredoc"));
}

char	*check_in_redir_str(char *s, int ap)
{
	char	*tem;
	char	*final;

	final = ft_strdup("");
	tem = rm_quot_dollar(s);
	if (ap == 1)
		tem = get_redir_strs(tem, final);
	free(final);
	free(s);
	return (tem);
}

int	ft_write_in(char *s, char **l_r, int *n, t_cmd *cmds)
{
	int		i;
	int		st;

	i = 0;
	if (s[++i] == '<')
	{
		cmds->i_ap = 1;
		i++;
	}
	else
		cmds->i_ap = 0;
	st = i;
	while (s[i] && (s[i] == ' '))
		i++;
	while (s[i])
	{
		i = pass_quotes(s, i);
		if (!s[i] || s[i] == ' ' || s[i] == '>' || s[i] == '<' || s[i] == '\t')
			break ;
		i++;
	}
	if ((*n) >= 1)
		l_r[--(*n)] = check_in_redir_str(ft_substr(s, st, i - st), cmds->i_ap);
	return (i);
}

void	print_message(void)
{
	extern t_minish	g_minish;

	printf("malloc error\n");
	g_minish.statu = 1;
}

int	ft_init_in_out(char ***r_s, char ***l_s, char **cmd, char *line)
{
	extern t_minish	g_minish;
	int				l_n;
	int				r_n;

	l_n = exit_redir(line, '<');
	r_n = exit_redir(line, '>');
	if (l_n > 0)
		*l_s = malloc (sizeof(char *) * (l_n + 1));
	if (r_n > 0)
		*r_s = malloc (sizeof(char *) * (r_n + 1));
	*cmd = malloc (sizeof(char ) * (ft_strlen(line) + 1));
	if (l_n > 0 || r_n > 0)
	{
		if (r_n && (!(*r_s) || !(*cmd)))
		{
			print_message();
			return (1);
		}
		if (l_n && (!(*l_s) || !(*cmd)))
		{
			print_message();
			return (1);
		}
	}
	return (0);
}
