/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:38:10 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 12:21:03 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_pwd(t_cmd *cmds)
{
	extern t_minish	g_minish;
	char			*pwd;
	char			*cmd;
	char			*s;

	cmd = cmds->p_line;
	if (*(cmd + 2))
	{
		s = ft_strtrim(cmd + 2, " ");
		if (s && s[0] == '-')
		{
			printf("pwd : no option for pwd\n");
			free(s);
			exit (1);
		}
		free(s);
	}
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	g_minish.statu = 0;
}

int	ft_add_and_delet(char **vars, char *tem, char *s)
{
	extern t_minish	g_minish;
	int				i;

	i = -1;
	while (vars[++i])
	{
		if (!ft_strcmp(vars[i], tem))
		{
			env_delet_var(&g_minish.env, tem);
			ft_add_strs(&g_minish.env, s);
			free(tem);
			ft_frees(vars);
			return (1);
		}
	}
	return (0);
}
