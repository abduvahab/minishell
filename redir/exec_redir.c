/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:35:28 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 12:37:19 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exit_redir(char *s, char c)
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
			if (s[i] == c)
			{
				n++;
				if (s[i + 1] && s[i + 1] == c)
					i++;
			}
			i++;
		}
	}
	return (n);
}

void	set_in_out_file(char **r_r, char **l_r, char *cmd, t_cmd *cmds)
{
	char	*line;
	int		i;
	int		j;
	int		l_n;
	int		r_n;

	i = 0;
	j = 0;
	line = cmds->p_line;
	l_n = exit_redir(line, '<');
	r_n = exit_redir(line, '>');
	while (line[i])
	{
		if (line[i] == '<')
			i += ft_write_in(line + i, l_r, &l_n, cmds);
		else if (line[i] == '>')
			i += ft_write_out(line + i, r_r, &r_n, cmds);
		else
			cmd[j++] = line[i++];
	}
	cmd[j] = '\0';
	if (l_n > 0)
		l_r[l_n] = NULL;
	if (r_n > 0)
		r_r[r_n] = NULL;
}

int	set_strs_cmds(char **r_r, char **l_r, t_cmd *cmds)
{
	int		i;
	int		t_l;
	int		t_r;

	i = -1;
	t_l = exit_redir(cmds->p_line, '<');
	t_r = exit_redir(cmds->p_line, '>');
	while (++i < t_l)
	{
		if (set_infile_cmds(l_r, i, cmds))
			return (1);
		free(l_r[i]);
	}
	i = -1;
	while (++i < t_r)
	{
		if (set_outfile_cmds(r_r, i, cmds))
			return (1);
		free(r_r[i]);
	}
	if (t_l > 0)
		free(l_r);
	if (t_r > 0)
		free(r_r);
	return (0);
}

int	is_unique_built(t_cmd *cmds)
{
	if (!ft_strcmp(cmds->cmds[0], "exit"))
		return (1);
	else if (!ft_strcmp(cmds->cmds[0], "export") && (cmds->cmds[1]))
		return (1);
	else if (!ft_strcmp(cmds->cmds[0], "unset"))
		return (1);
	if (!ft_strcmp(cmds->cmds[0], "cd"))
		return (1);
	return (0);
}

int	exec_redir(t_cmd *cmds)
{
	char	*line;
	char	*cmd;
	char	**r_r;
	char	**l_r;

	line = cmds->p_line;
	if (ft_init_in_out(&r_r, &l_r, &cmd, line))
		return (1);
	set_in_out_file(r_r, l_r, cmd, cmds);
	if (set_strs_cmds(r_r, l_r, cmds))
	{
		free(cmd);
		return (1);
	}
	cmds->p_line = ft_strtrim(cmd, " \t");
	get_order(cmds);
	free(cmd);
	return (0);
}
