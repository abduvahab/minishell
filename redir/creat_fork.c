/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:21:40 by areheman          #+#    #+#             */
/*   Updated: 2022/10/06 19:44:52 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fork_child(t_cmd *cmds)
{
	extern t_minish	g_minish;
	char			**cmd;
	int				s;

	cmd = cmds->cmds;
	if (cmds->infd != 0)
		dup2(cmds->infd, 0);
	if (cmds->outfd != 1)
		dup2(cmds->outfd, 1);
	if (is_built_cmd(cmd[0]))
	{
		exc_built(cmd[0], cmds);
		exit (0);
	}
	s = my_execve(cmd[0], cmd);
	if (s != 0)
		exit (s);
}

void	fork_father(t_cmd *cmds, pid_t pd)
{
	extern t_minish	g_minish;
	int				status;

	if (cmds->l_pd == 2 || cmds->l_pd == 1)
	{
		waitpid(pd, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 0)
				g_minish.statu = 0;
			else
				g_minish.statu = WEXITSTATUS(status);
		}
	}
	if (cmds->infd != 0)
		close(cmds->infd);
	if (cmds->outfd != 1)
		close(cmds->outfd);
}

void	creat_fork(t_cmd *cmds)
{
	extern t_minish	g_minish;
	pid_t			pd;

	pd = fork();
	if (pd < 0)
	{
		printf("fork error !");
		g_minish.statu = 1;
		return ;
	}
	if (pd == 0)
		fork_child(cmds);
	else
		fork_father(cmds, pd);
}
