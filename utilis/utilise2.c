/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:00:01 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 10:01:28 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_frees(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	if (s)
		free(s);
}

void	ft_free_cmds(t_cmd *cmds)
{
	ft_frees(cmds->cmds);
	if (cmds->p_line)
		free(cmds->p_line);
	if (cmds->infile)
		free(cmds->infile);
	if (cmds->outfile)
		free(cmds->outfile);
}

int	count_pipe(char *s)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			i = pass_quotes(s, i);
		else
		{
			if (s[i] == '|')
				n++;
			i++;
		}
	}
	return (n);
}

char	**all_env_var(void)
{
	extern t_minish	g_minish;
	char			**s;
	char			**tem;
	char			**en;
	int				i;

	i = 0;
	s = g_minish.env;
	while (s[i])
		i++;
	en = malloc(sizeof(char *) * (1 + i));
	if (!en)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tem = ft_split(s[i], '=');
		en[i] = ft_strdup(*tem);
		ft_frees(tem);
		i++;
	}
	en[i] = NULL;
	return (en);
}

char	*rm_quots2(char *s)
{
	int		*n_q;
	char	*line;

	if (!s)
		return (NULL);
	line = ft_strtrim(s, " ");
	n_q = count_qouts(line);
	if ((n_q[0] > 0) || (n_q[1] > 0))
		line = rm_qouts(line, n_q);
	return (line);
}
