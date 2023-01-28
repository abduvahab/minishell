/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:59:06 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 13:08:33 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_el(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_cd_strjoin(char *var, char *value)
{
	char	*final;
	char	*tem;

	var = ft_strjoin2(var, "/");
	tem = ft_strtrim(value, " ");
	final = ft_strjoin2(var, tem);
	free(tem);
	return (final);
}

char	*ft_find_dir(char *cmd)
{
	extern t_minish	g_minish;
	char			*pwd;
	char			*tem;
	char			*home;

	pwd = getcwd(NULL, 0);
	if (!ft_strcmp(cmd, "cd"))
		home = env_get_value(g_minish.env, "HOME");
	else
	{
		tem = rm_quot_dollar(cmd + 2);
		if (tem[0] == '~')
		{
			home = ft_cd_strjoin(env_get_value(g_minish.env, \
			"HOME"), (tem + 1));
		}
		else if (tem[0] != '/' && tem[0] != '.')
			home = ft_cd_strjoin(pwd, (tem));
		else
			home = ft_strdup(tem);
		free(tem);
	}
	free(pwd);
	return (home);
}

void	exec_cd(char *cmd)
{
	extern t_minish	g_minish;
	char			*pwd;
	char			*home;

	pwd = getcwd(NULL, 0);
	home = ft_find_dir(cmd);
	if (chdir(home) != 0)
	{
		printf("no such file or directory!\n");
		free(pwd);
		free(home);
		g_minish.statu = 1;
		return ;
	}
	env_set_value(g_minish.env, "OLDPWD", pwd);
	free(pwd);
	pwd = getcwd(NULL, 0);
	env_set_value(g_minish.env, "PWD", pwd);
	free(pwd);
	g_minish.statu = 0;
	free(home);
}
