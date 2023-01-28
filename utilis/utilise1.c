/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:30:49 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 13:07:14 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	s1_len;
	int	s2_len;

	i = 0;
	if (!s1 || !s2)
		return (1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	while (i < s1_len && i < s2_len)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (i < s1_len || i < s2_len)
		return (1);
	return (0);
}

int	ft_arespaces(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\f');
}

int	pass_quotes(char *str, int n)
{
	int	i;
	int	q;

	i = n;
	q = 0;
	if ((str[i] == '\'' || str[i] == '\"') && !q)
	{
		q = str[i];
		i++;
	}
	while (q && str[i] != q)
		i++;
	if (q && str[i] == q)
	{
		q = 0;
		i++;
	}
	return (i);
}

char	*ft_strjoin_str(char *var, char *value, char *mid)
{
	char	*final;
	char	*tem1;
	char	*tem2;

	tem1 = ft_strjoin(var, mid);
	tem2 = ft_strtrim(value, " ");
	final = ft_strjoin(tem1, tem2);
	free(tem1);
	free(tem2);
	return (final);
}
