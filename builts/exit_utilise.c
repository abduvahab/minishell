/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utilise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:48:01 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 13:47:12 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_numeric(char *arg)
{
	int				i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (arg[i] != '\f' && arg[i] != '\t' && arg[i] != '\r'
			&& arg[i] != '\v' && arg[i] != ' ')
		{
			if (arg[i] < 48 || arg[i] > 57)
				return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_echo_joins(char **strs)
{
	char	*f;
	char	*tem;
	int		i;

	i = 0;
	f = ft_strdup("");
	while (strs[i])
	{
		if (i == 0)
			tem = ft_strdup(strs[i]);
		else
			tem = ft_strjoin2(ft_strdup(" "), strs[i]);
		f = ft_strjoin2(f, tem);
		free(tem);
		i++;
	}
	return (f);
}

int	find_echo_str(char **tem, int i)
{
	char	*tem2;

	while (tem[i] && tem[i][0] == '-')
	{
		tem2 = ft_strtrim(tem[i], "n");
		if (ft_strcmp(tem2, "-"))
		{
			free(tem2);
			break ;
		}
		i++;
		free(tem2);
	}
	if (!tem2)
		free(tem2);
	return (i);
}

void	handle_export_str(char *tem)
{
	extern t_minish	g_minish;
	char			*line;
	char			*tem2;
	int				n;

	line = ft_strtrim(tem, " ");
	n = number_strs(line);
	if (n > 0)
		check_export_str(line, n);
	else
	{
		if (check_split_export(line))
		{
			printf("export: %s not valid identifier\n", line);
			g_minish.statu = 1;
			free(line);
			return ;
		}
		tem2 = rm_quot_dollar(line);
		write_export_str(tem2);
		free(tem2);
		free(line);
	}
}

int	is_same_str(char *s, char **vars)
{
	int	i;

	i = 0;
	while (vars[i])
	{
		if (!ft_strcmp(vars[i], s))
			return (1);
		i++;
	}
	return (0);
}
