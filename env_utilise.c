/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utilise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:29:56 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 13:03:15 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_copy(char **s)
{
	int		i;
	char	**en;

	i = 0;
	while (s[i])
		i++;
	en = (char **)malloc(sizeof(char *) * (i + 1));
	if (!en)
		return (NULL);
	i = 0;
	while (s[i])
	{
		en[i] = ft_strdup(s[i]);
		i++;
	}
	en[i] = NULL;
	return (en);
}

char	*env_get_value(char **envs, char *s)
{
	char	*tem;
	char	*tem1;
	int		i;

	i = 0;
	while (envs[i])
	{
		if (!ft_strncmp(envs[i], s, ft_strlen(s)))
		{
			if (envs[i][ft_strlen(s)] == '=')
			{
				tem = ft_strchr(envs[i], '=') + 1;
				tem1 = ft_strdup(tem);
				return (tem1);
			}
		}
		i++;
	}
	return (0);
}

int	env_set_value(char **envs, char *var, char *value)
{
	int	i;

	i = 0;
	while (envs[i])
	{
		if (!ft_strncmp(envs[i], var, ft_strlen(var)))
		{
			if (envs[i][ft_strlen(var)] == '=')
			{
				free(envs[i]);
				envs[i] = ft_strjoin_str(var, value, "=");
				if (!envs[i])
					return (0);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	env_set_var(char ***env, char *var, char *value)
{
	int		i;
	char	**envs;
	char	**n_env;
	char	*tem;

	i = 0;
	envs = *env;
	while (envs[i])
		i++;
	n_env = malloc(sizeof(char *) * (i + 2));
	if (!n_env)
		return (0);
	tem = ft_strjoin2(ft_strtrim(var, " "), "=");
	value = ft_strtrim(value, " ");
	n_env[i] = ft_strjoin2(tem, value);
	n_env[i + 1] = NULL;
	while (--i >= 0)
		n_env[i] = ft_strdup(envs[i]);
	free(value);
	ft_frees(*env);
	*env = n_env;
	return (1);
}

int	env_delet_var(char ***env, char *var)
{
	int		i;
	int		j;
	char	**envs;
	char	**n_env;

	i = 0;
	envs = *env;
	while (envs[i])
		i++;
	n_env = malloc(sizeof(char *) * (i));
	i = 0;
	j = 0;
	while (envs[i])
	{
		if (!ft_strncmp(envs[i], var, ft_strlen(var)) \
			&& envs[i][ft_strlen(var)] == '=')
			i++;
		if (envs[i])
			n_env[j++] = ft_strdup(envs[i++]);
	}
	n_env[j] = NULL;
	ft_frees(*env);
	*env = n_env;
	return (1);
}
