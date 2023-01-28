/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:08:01 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 14:36:49 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_dollar_str(char *s)
{
	int		n;
	char	*ds;

	n = 0;
	if (s[0] == '?')
	{
		ds = ft_strdup("?");
		return (ds);
	}
	if (s[0] == '*' || ft_isdigit(s[0]))
		return (ft_strdup("*"));
	while (s[n] && (ft_isalnum(s[n])))
		n++;
	ds = malloc(sizeof(char) * (n + 1));
	if (!ds)
		return (NULL);
	ds[n] = '\0';
	while (--n >= 0)
	{
		ds[n] = s[n];
	}
	return (ds);
}

int	pass_sigle_quot(char *str, int n)
{
	int	i;
	int	q;

	i = n;
	q = 0;
	if ((str[i] == '\'') && !q)
	{
		q = str[i];
		i++;
	}
	while (q == '\'' && str[i] != '\'')
		i++;
	if (q && str[i] == q)
	{
		q = 0;
		i++;
	}
	return (i);
}

int	ft_write_dollar_str(char *s, char **d_vs, int i, int *n)
{
	char	*d_s;
	char	*tem;
	int		j;
	int		m;

	j = *n;
	d_vs[j] = ft_substr(s, 0, i);
	if (*(d_vs[j]))
		j++;
	else
		free(d_vs[j]);
	d_s = get_dollar_str(s + i + 1);
	tem = get_value_dollar(d_s);
	if (tem)
	{
		d_vs[j] = ft_strdup(tem);
		free(tem);
		j++;
	}
	*n = j;
	m = ft_strlen(d_s);
	free(d_s);
	return (m);
}

void	write_dollar_str(char *s, char **d_vs)
{
	int		i;
	int		j;
	int		d;

	i = 0;
	d = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] && s[i] == '\'')
			i = pass_sigle_quot(s, i);
		else
		{
			if (s[i] == '$' && is_dollar_write(s, i))
			{
				d = i + 1 + ft_write_dollar_str(s + d, d_vs, i - d, &j);
				i = d - 1;
			}
			i++;
		}
	}
	d_vs[j++] = ft_substr(s, d, i - d);
	d_vs[j] = NULL;
}

char	*replace_dollar(char *s, int n)
{
	char	**d_vs;
	char	*final;
	int		j;

	j = 0;
	d_vs = malloc(sizeof(char *) * (1 + (n * 2) + 1));
	if (!d_vs)
		return (NULL);
	write_dollar_str(s, d_vs);
	final = malloc(sizeof(char));
	*final = '\0';
	j = 0;
	while (d_vs[j])
	{
		final = ft_strjoin2(final, d_vs[j]);
		j++;
	}
	ft_frees(d_vs);
	free(s);
	return (final);
}
