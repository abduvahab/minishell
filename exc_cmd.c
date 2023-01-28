/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:47:35 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 13:55:09 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_t_cmds_init(t_cmd *cmds, char *line, int n)
{
	extern t_minish	g_minish;

	cmds->p_line = line;
	cmds->cmds = malloc(sizeof(char *) * 4);
	if (!cmds->cmds)
	{
		g_minish.statu = 1;
		printf("malloc error");
		return ;
	}
	cmds->cmds[0] = NULL;
	cmds->cmds[1] = NULL;
	cmds->cmds[2] = NULL;
	cmds->cmds[3] = NULL;
	cmds->infd = 0;
	cmds->outfd = 1;
	cmds->i_ap = 0;
	cmds->o_ap = 0;
	cmds->pipe = n;
	cmds->l_pd = 0;
	cmds->infile = NULL;
	cmds->outfile = NULL;
}

void	exc_built(char *cmd, t_cmd *cmds)
{
	if (!ft_strcmp(cmd, "cd"))
		exec_cd(cmds->p_line);
	else if (!ft_strcmp(cmd, "unset"))
		exec_unset(cmds->p_line);
	else if (!ft_strcmp(cmd, "export"))
		exec_export(cmds);
	else if (!ft_strcmp(cmd, "exit"))
		return ;
	else if (!ft_strcmp(cmd, "echo"))
		exec_echo(cmds);
	else if (!ft_strcmp(cmd, "env"))
		exec_env(cmds);
	else if (!ft_strcmp(cmd, "pwd"))
		exec_pwd(cmds);
}

int	is_built_cmd(char *s)
{
	if (!ft_strcmp(s, "cd"))
		return (1);
	if (!ft_strcmp(s, "unset"))
		return (1);
	if (!ft_strcmp(s, "exit"))
		return (1);
	if (!ft_strcmp(s, "export"))
		return (1);
	if (!ft_strcmp(s, "echo"))
		return (1);
	if (!ft_strcmp(s, "env"))
		return (1);
	if (!ft_strcmp(s, "pwd"))
		return (1);
	return (0);
}

void	exec_order(t_cmd *cmds)
{
	if (cmds->pipe == 0 && is_unique_built(cmds))
	{
		if (!ft_strcmp(cmds->cmds[0], "exit"))
			exc_exit(cmds->p_line);
		if (!ft_strcmp(cmds->cmds[0], "cd"))
			exec_cd(cmds->p_line);
		else if (!ft_strcmp(cmds->cmds[0], "export") && (cmds->cmds[1]))
			exec_export(cmds);
		else if (!ft_strcmp(cmds->cmds[0], "unset"))
			exec_unset(cmds->p_line);
		return ;
	}
	if (set_fdfile_open(cmds) == -1)
	{
		printf(" No such file or directory\n");
		return ;
	}
	creat_fork(cmds);
}

void	exc_cmd(char *line)
{
	extern t_minish	g_minish;
	char			*n_line;
	t_cmd			cmds;
	int				n_p;

	g_minish.sig = 2;
	n_line = ft_strtrim(line, " \t");
	n_p = count_pipe(n_line);
	if (n_p > 0)
		exec_pipe(n_line, n_p);
	else
	{
		ft_t_cmds_init(&cmds, n_line, 0);
		if (exec_redir(&cmds) == 0)
			exec_order(&cmds);
		ft_free_cmds(&cmds);
	}
	free(n_line);
}
