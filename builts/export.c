/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:15:04 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 13:45:36 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	output_export(int fd)
{
	extern t_minish	g_minish;
	char			**vars;
	char			*tem;
	int				i;

	(void)fd;
	vars = all_env_var();
	i = -1;
	while (vars[++i])
	{
		tem = env_get_value(g_minish.env, vars[i]);
		printf("declare -x %s=\"%s\"\n", vars[i], tem);
		free(tem);
	}
	if (g_minish.expo)
	{
		i = 0;
		while (g_minish.expo[i])
		{
			printf("declare -x %s\n", g_minish.expo[i]);
			i++;
		}
	}
	ft_frees(vars);
}

void	ft_add_strs(char ***bs, char *s)
{
	char	**tem;
	int		i;

	if (!(*bs))
	{
		tem = malloc(sizeof(char *) * 2);
		tem[1] = NULL;
		tem[0] = ft_strdup(s);
	}
	else
	{
		i = 1;
		while ((*bs)[i])
			i++;
		tem = malloc(sizeof(char *) * (i + 2));
		if (!tem)
			return ;
		tem[i + 1] = NULL;
		tem[i] = ft_strdup(s);
		while (--i >= 0)
			tem[i] = ft_strdup((*bs)[i]);
		ft_frees(*bs);
	}
	*bs = tem;
}

void	write_export_str(char *s)
{
	extern t_minish	g_minish;

	if (ft_strchr(s, '='))
	{
		if (!is_in_env(s))
			ft_add_strs(&g_minish.env, s);
	}
	else
	{
		if (!is_in_exprt(s))
			ft_add_strs(&g_minish.expo, s);
	}
}

void	check_export_str(char *line, int n)
{
	extern t_minish	g_minish;
	char			*tem;
	char			**s;
	int				i;

	s = malloc(sizeof(char *) * (n + 2));
	rm_space_echo(line, s);
	i = 0;
	while (s[i])
	{
		if (check_split_export(s[i]))
		{
			printf("export: %s not valid identifier\n", s[i++]);
			g_minish.statu = 1;
		}
		else
		{
			tem = rm_quot_dollar(s[i]);
			write_export_str(tem);
			free(tem);
			i++;
		}
	}
	free(line);
	ft_frees(s);
}

void	exec_export(t_cmd *cmds)
{
	extern t_minish	g_minish;
	char			*tem;
	char			*line;

	g_minish.statu = 0;
	line = cmds->p_line;
	if (!ft_strcmp(line, "export"))
		output_export(cmds->outfd);
	else
	{
		tem = line + 6;
		tem = ft_substr(tem, 0, ft_strlen(tem));
		handle_export_str(tem);
		free(tem);
	}
}
