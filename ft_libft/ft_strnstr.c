/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:38:47 by areheman          #+#    #+#             */
/*   Updated: 2022/03/01 15:50:02 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *m_str, const char *s_str, size_t n)
{
	size_t		i;
	size_t		j;
	char		*m;
	char		*s;

	m = (char *)m_str;
	s = (char *)s_str;
	if (!*s)
		return (m);
	i = 0;
	while (m[i] && i < n)
	{
		j = 0;
		if (m[i] == s[j])
		{
			j += 1;
			while (m[i + j] && s[j] && m[i + j] == s[j] && i + j < n)
				j++;
		}
		if (s[j] == '\0')
			return (&m[i]);
		i++;
	}
	return (0);
}
