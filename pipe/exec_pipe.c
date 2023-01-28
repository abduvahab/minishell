/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:19:25 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 15:06:39 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**init_cmds_str(int n)
{
	extern t_minish	g_minish;
	char			**cmds;

	cmds = malloc(sizeof(char *) * (n + 2));
	if (!cmds)
	{
		g_minish.statu = 1;
		printf("malloc error");
		return (NULL);
	}
	return (cmds);
}

void	ft_p_cmds_value(t_cmd **p, char *s, int n)
{
	*p = malloc(sizeof(t_cmd));
	if (!(*p))
	{
		printf("malloc error!");
		return ;
	}
	ft_t_cmds_init(*p, s, n);
}

t_cmd	**init_p_cmds(int n, char **cmds)
{
	extern t_minish	g_minish;
	t_cmd			**p_cmds;
	int				i;

	p_cmds = malloc(sizeof(t_cmd *) * (n + 2));
	if (!p_cmds)
	{
		g_minish.statu = 1;
		printf("malloc error");
		return (NULL);
	}
	i = 0;
	n++;
	i = -1;
	while (++i < n)
		ft_p_cmds_value(&(p_cmds[i]), cmds[i], n - 1);
	p_cmds[i] = NULL;
	return (p_cmds);
}

void	exec_pipe_order(t_cmd **p_cmds, int n)
{
	int		i;
	int		m;

	i = 0;
	while (i < n)
	{
		exec_redir(p_cmds[i]);
		i++;
	}
	m = exit_cat_wc(p_cmds);
	if (m == n)
	{
		if (all_is_cat(p_cmds, n))
			exec_cat();
		else
			exec_wc();
	}
	else if (m == 0)
		exec_pipes_unique(p_cmds, n);
	else if (m < n)
		exec_mix(p_cmds, n, m);
}

void	exec_pipe(char *line, int n)
{
	char	**cmds;
	t_cmd	**p_cmds;

	cmds = get_pipe_strs(line, n);
	p_cmds = init_p_cmds(n, cmds);
	n++;
	exec_pipe_order(p_cmds, n);
	ft_frees(cmds);
	free_p_cmds(p_cmds);
	free(p_cmds);
}
