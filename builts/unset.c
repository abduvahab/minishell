/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:13:45 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 12:20:54 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_unset_export(char *s)
{
	if (check_split_export(s))
		return (1);
	if (ft_strchr(s, '='))
		return (1);
	return (0);
}

void	unset_str(char *s)
{
	extern t_minish	g_minish;

	if (is_unset_export(s))
	{
		ft_delete_str(&g_minish.expo, s);
		return ;
	}
	if (is_unset_env(s))
	{
		env_delet_var(&g_minish.env, s);
		return ;
	}
}

void	check_unset_str(char **s)
{
	extern t_minish	g_minish;
	char			*tem;
	int				i;

	i = -1;
	while (s[++i])
	{
		if (check_unset_export(s[i]))
		{
			printf("unset: %s not valid identifier\n", s[i]);
			if (!s[i + 1])
				g_minish.statu = 1;
		}
		else
		{
			tem = rm_quot_dollar(s[i]);
			unset_str(tem);
			free(tem);
			if (!s[i + 1])
				g_minish.statu = 0;
		}
	}
}

void	exec_unset(char *line)
{
	extern t_minish	g_minish;
	char			*tem;
	char			**home;

	if (!ft_strcmp(line, "unset"))
	{
		g_minish.statu = 0;
		return ;
	}
	else
	{
		tem = line + 5;
		tem = ft_strtrim(tem, " ");
		home = ft_split(tem, ' ');
		free(tem);
		check_unset_str(home);
		ft_frees(home);
	}
}
