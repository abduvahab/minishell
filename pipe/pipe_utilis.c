/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:44:45 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 17:51:35 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_pipe(char *s)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (s[i])
	{
		if (s[i] == '\"' || s[i] == '\'')
			i = pass_quotes(s, i);
		else
		{
			if (s[i] == '|')
				return (i);
			i++;
		}
	}
	return (-1);
}

char	**get_pipe_strs(char *line, int n)
{
	char	**cmds;
	char	*tem;
	size_t	i;
	int		j;

	cmds = init_cmds_str(n);
	j = 0;
	tem = line;
	while (j < n + 1)
	{
		i = 0;
		if ((find_pipe(tem)) != -1)
		{
			i = find_pipe(tem);
			cmds[j] = ft_substr(tem, 0, i);
			tem += (i + 1);
		}
		else
			cmds[j] = ft_strdup(tem);
		j++;
	}
	cmds[j] = NULL;
	return (cmds);
}

void	free_p_cmds(t_cmd **p_cmds)
{
	int		i;

	i = 0;
	while (p_cmds[i])
	{
		ft_free_cmds(p_cmds[i]);
		free(p_cmds[i]);
		i++;
	}
}
