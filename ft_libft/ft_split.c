/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:38:37 by areheman          #+#    #+#             */
/*   Updated: 2022/10/05 12:31:44 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pointers(char const *s, char c)
{
	size_t	i;
	int		pts;

	i = 0;
	pts = 0;
	while (s[i])
	{
		if (s[i] != c && i < ft_strlen(s))
		{
			while (s[i] != c && i < ft_strlen(s))
				i++;
			pts++;
		}
		else
			i++;
	}
	return (pts);
}

static char	**ft_opens(char **ss, char const *s, char c)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i] && i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			k = 0;
			while (s[i] != c && i < ft_strlen(s))
			{
				k++;
				i++;
			}
			ss[j] = (char *)malloc(sizeof(char) * (k + 1));
			if (!ss[j])
				return (0);
			j++;
		}
		else
			i++;
	}
	return (ss);
}

static char	**ft_putstrs(char **ss, char const *s, char c)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i] && i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != c && i < ft_strlen(s))
			{
				ss[k][j] = s[i];
				j++;
				i++;
			}
			ss[k][j] = '\0';
			k++;
		}
		else
			i++;
	}
	ss[k] = NULL;
	return (ss);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;
	int		pts;

	if (!s)
		return (0);
	pts = ft_pointers(s, c);
	ss = (char **)malloc(sizeof(char *) * (pts + 1));
	if (!ss)
		return (0);
	ss = ft_opens(ss, s, c);
	if (!ss)
		return (0);
	ss = ft_putstrs(ss, s, c);
	return (ss);
}
