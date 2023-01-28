/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:38:50 by areheman          #+#    #+#             */
/*   Updated: 2022/10/01 13:40:12 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_env(t_cmd *cmds)
{
	extern t_minish	g_minish;
	char			**s;
	char			*cmd;
	int				i;

	cmd = cmds->p_line;
	if (!ft_strcmp(cmd, "env"))
	{
		i = 0;
		s = g_minish.env;
		while (s[i])
		{
			ft_putstr_fd(s[i++], cmds->outfd);
			ft_putstr_fd("\n", cmds->outfd);
		}
	}
	else
	{
		printf("env : can't have option or arguments\n");
		exit(1);
	}
}
