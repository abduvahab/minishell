/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:47:28 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 12:55:21 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	second_part(char *s, char ***cmd)
{
	char	*line;
	int		n;

	n = 0;
	line = ft_strtrim(s, " ");
	if (!(*line))
	{
		(*cmd)[2] = NULL;
		return ;
	}
	(*cmd)[2] = rm_quot_dollar(line);
	free(line);
}

static void	get_line_part(char *line, char ***cmd)
{
	int		n;

	n = 0;
	while (line[n] && line[n] != ' ')
		n++;
	(*cmd)[1] = ft_substr(line, 0, n);
	if (line[n])
		second_part(line + n, cmd);
	else
		(*cmd)[2] = NULL;
}

static void	first_part(char *s, char ***cmd)
{
	extern t_minish	g_minish;
	char			*line;
	int				n;

	n = 0;
	line = ft_strtrim(s, " ");
	if (!(*line))
	{
		(*cmd)[1] = NULL;
		(*cmd)[2] = NULL;
		return ;
	}
	if (line[0] == '-')
		get_line_part(line, cmd);
	else
	{
		(*cmd)[1] = rm_quot_dollar(line);
		(*cmd)[2] = NULL;
	}
	free(line);
}

void	get_order(t_cmd *cmds)
{
	extern t_minish	g_minish;
	char			**cmd;
	char			*s;
	int				i;

	cmd = cmds->cmds;
	s = cmds->p_line;
	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	cmd[0] = ft_substr(s, 0, i);
	if (!cmd[0])
		return ;
	if (s[i])
		first_part(s + i, &cmd);
	else
	{
		cmd[1] = NULL;
		cmd[2] = NULL;
	}
}

int	set_fdfile_open(t_cmd *cmds)
{
	if (cmds->pipe == 0)
		cmds->l_pd = 1;
	if (cmds->infile)
	{
		cmds->infd = open(cmds->infile, O_RDONLY);
		if (cmds->infd == -1)
			return (-1);
	}
	if (cmds->outfile)
	{
		if (cmds->o_ap)
			cmds->outfd = open(cmds->outfile, O_WRONLY \
			| O_CREAT | O_APPEND, 0666);
		else
			cmds->outfd = open(cmds->outfile, \
						O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if (cmds->outfd == -1)
		{
			printf(" %s:open not success\n", cmds->outfile);
			return (-1);
		}
	}
	return (0);
}

/*
void	exec_order(t_cmd *cmds)
{
	if (cmds->pipe == 0)
		cmds->l_pd = 1;
	if (cmds->infile)
	{
		cmds->infd = open(cmds->infile, O_RDONLY);
		if (cmds->infd == -1)
		{
			printf(" %s: No such file or directory\n", cmds->infile);
			return ;
		}
	}
	if (cmds->outfile)
	{
		if (cmds->o_ap)
			cmds->outfd = open(cmds->outfile, O_WRONLY \
			| O_CREAT | O_APPEND, 0666);
		else
			cmds->outfd = open(cmds->outfile, \
						O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if (cmds->outfd == -1)
		{
			printf(" %s:open not success\n", cmds->outfile);
			return ;
		}
	}
	//creat_fork(cmds);
}
*/