/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:55:29 by areheman          #+#    #+#             */
/*   Updated: 2022/03/10 16:53:32 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*s;
	int		i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	s = (char *)str;
	while ((s[i] >= 9 & s[i] <= 13) || s[i] == 32)
	{
		i++;
	}
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= (-1);
		i++;
	}
	result = 0;
	while (ft_isdigit(s[i]))
	{
		result = result * 10 + s[i] - 48;
		i++;
	}
	return ((int)(result * sign));
}
