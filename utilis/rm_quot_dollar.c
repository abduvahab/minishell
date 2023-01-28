/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quot_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:49:18 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 11:03:20 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_dollars(char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			i = pass_sigle_quot(s, i);
		else
		{
			if (s[i] == '$')
				n++;
			i++;
		}
	}
	return (n);
}

char	*init_str_quots(char *s, int *n)
{
	char	*line;
	int		i;
	int		m;

	line = malloc(sizeof(char) * (ft_strlen(s) + 1 - (n[0]) * 2) - (n[1] * 2));
	if (!line)
		return (NULL);
	i = 0;
	m = (int)ft_strlen(s) - (n[0]) * 2 - (n[1] * 2);
	while (i < m)
	{
		line[i] = '\0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*rm_qouts(char *s, int *n)
{
	char	*line;
	int		i;
	int		j;
	int		q;

	i = 0;
	j = 0;
	q = 0;
	line = init_str_quots(s, n);
	while (s[i])
	{
		if ((s[i] == '\'' || s[i] == '\"') && !q)
			q = s[i++];
		while ((q == '\'' && s[i] != '\'') || (q == '\"' && s[i] != '\"'))
			line[j++] = s[i++];
		if (q && s[i] == q)
		{
			q = 0;
			i++;
		}
		if (s[i] && s[i] != '\'' && s[i] != '\"')
			line[j++] = s[i++];
	}
	free(s);
	return (line);
}

int	*count_qouts(char *str)
{
	int	i;
	int	q;
	int	*n;

	i = 0;
	n = malloc(sizeof(int) * 2);
	n[0] = 0;
	n[1] = 0;
	q = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && !q)
			q = str[i];
		else if (q && str[i] == q)
		{
			q = 0;
			if (str[i] == '\'')
				n[0]++;
			else
				n[1]++;
		}
		i++;
	}
	return (n);
}

char	*rm_quot_dollar(char *s)
{
	int		n_d;
	int		*n_q;
	char	*line;
	char	*tem;

	if (!s)
		return (NULL);
	line = ft_strtrim(s, " ");
	n_q = count_qouts(line);
	n_d = count_dollars(line);
	if (n_d > 0)
		line = replace_dollar(line, n_d);
	if ((n_q[0] > 0) || (n_q[1] > 0))
		line = rm_qouts(line, n_q);
	free(n_q);
	tem = ft_strtrim(line, " ");
	free(line);
	return (tem);
}
