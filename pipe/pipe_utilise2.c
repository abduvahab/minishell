/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utilise2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:23:18 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 14:58:24 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exit_cat_wc(t_cmd **p_cmds)
{
	int	m;

	m = 0;
	while (p_cmds[m] && ((((!ft_strcmp(p_cmds[m]->cmds[0], "cat") \
			&& p_cmds[m]->cmds[1] == NULL && p_cmds[m]->infile == NULL) \
			|| (!ft_strcmp(p_cmds[m]->cmds[0], "/bin/cat") \
			&& p_cmds[m]->cmds[1] == NULL && p_cmds[m]->infile == NULL)) \
			&& (p_cmds[m]->cmds[2] == NULL)) \
			|| (!ft_strcmp(p_cmds[m]->cmds[0], "wc") \
			|| !ft_strcmp(p_cmds[m]->cmds[0], "/bin/wc"))))
		m++;
	return (m);
}

int	all_is_cat(t_cmd **p_cmds, int n)
{
	int		m;

	m = 0;
	while ((m < n) && (!ft_strcmp(p_cmds[m]->cmds[0], "cat") \
			|| !ft_strcmp(p_cmds[m]->cmds[0], "/bin/cat")) \
			&& (p_cmds[m]->cmds[2] == NULL))
		m++;
	if (m == n)
		return (1);
	return (0);
}

void	exec_wc(void)
{
	extern t_minish	g_minish;
	t_cmd			cmds;
	char			*line;

	g_minish.sig = 2;
	line = ft_strdup("wc");
	ft_t_cmds_init(&cmds, line, 0);
	cmds.cmds[0] = ft_strdup("wc");
	exec_order(&cmds);
	free(line);
	ft_frees((&cmds)->cmds);
}

void	exec_pipes_unique(t_cmd **p_cmds, int n)
{
	int	i;
	int	fds[2];

	i = 0;
	while (i < n)
	{
		if ((i < n - 1))
		{
			pipe(fds);
			p_cmds[i + 1]->infd = fds[0];
			p_cmds[i]->outfd = fds[1];
		}
		if (i == n - 1)
				p_cmds[i]->l_pd = 2;
		exec_order(p_cmds[i]);
		i++;
	}
	close(fds[0]);
	close(fds[1]);
}

void	exec_pipes_unique2(t_cmd **p_cmds, int n, int m)
{
	int	i;
	int	fds[2];
	int	f;

	i = m;
	f = 0;
	while (i < n)
	{
		if ((i < n - 1))
		{
			f = 1;
			pipe(fds);
			p_cmds[i + 1]->infd = fds[0];
			p_cmds[i]->outfd = fds[1];
		}
		if (i == n - 1)
				p_cmds[i]->l_pd = 2;
		exec_order(p_cmds[i]);
		i++;
	}
	if (f == 1)
	{
		close(fds[0]);
		close(fds[1]);
	}
}
