/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utilise3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:41:59 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 18:06:12 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cat_with_number(t_cmd **p_cmds, int n, int m)
{
	char	buf[2];
	int		i;

	exec_pipes_unique2(p_cmds, n, m);
	i = 0;
	while (i < m)
	{
		read(0, buf, 1);
		buf[1] = '\0';
		if (buf[0] == '\0')
			return ;
		i++;
	}
}

void	exec_mix(t_cmd **p_cmds, int n, int m)
{
	if (all_is_cat(p_cmds, m))
		cat_with_number(p_cmds, n, m);
	else
	{
		exec_pipes_unique2(p_cmds, n, m);
		exec_wc();
	}
}

void	exec_cat(void)
{
	extern t_minish	g_minish;
	t_cmd			cmds;
	char			*line;

	line = ft_strdup("wc");
	ft_t_cmds_init(&cmds, line, 0);
	cmds.cmds[0] = ft_strdup("cat");
	exec_order(&cmds);
	ft_free_cmds(&cmds);
}
