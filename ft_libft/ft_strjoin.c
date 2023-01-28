/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:39:33 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 14:10:16 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	i = -1;
	j = -1;
	while (s1[++i])
		p[i] = s1[i];
	while (s2[++j])
		p[i + j] = s2[j];
	p[i + j] = '\0';
	return (p);
}
