/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:37:59 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 15:40:18 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_access(char *cmd, char **paths)
{
	char	*tem1;
	char	*tem;
	int		i;

	i = 0;
	while (paths[i])
	{
		tem = ft_strjoin(paths[i], "/");
		tem1 = ft_strjoin(tem, cmd);
		if (access(tem1, F_OK) == 0)
		{
			free(tem1);
			free(tem);
			return (1);
		}
		free(tem1);
		free(tem);
		i++;
	}
	return (0);
}

char	*get_path_env(char *cmd, char **paths)
{
	char	*tem1;
	char	*tem2;
	int		i;

	i = 0;
	while (paths[i])
	{
		tem1 = ft_strjoin(paths[i], "/");
		tem2 = ft_strjoin(tem1, cmd);
		if (access(tem2, F_OK) == 0)
		{
			return (tem2);
		}
		free(tem1);
		free(tem2);
		i++;
	}
	return (0);
}

int	my_execve(char *cmd, char *arg[])
{
	extern t_minish	g_minish;
	char			**paths;
	char			*ph;

	if (cmd && cmd[0] == '/')
		execve (cmd, arg, g_minish.env);
	ph = env_get_value(g_minish.env, "PATH");
	paths = ft_split(ph, ':');
	if (is_access(cmd, paths))
	{
		cmd = get_path_env(cmd, paths);
		free(ph);
		ft_frees(paths);
		execve (cmd, arg, g_minish.env);
	}
	printf("Error :%s: command not found --!\n", cmd);
	free(ph);
	ft_frees(paths);
	return (127);
}
