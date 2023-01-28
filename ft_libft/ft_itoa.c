/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:54:04 by areheman          #+#    #+#             */
/*   Updated: 2022/03/08 16:42:25 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numdigit(int n)
{
	int	num;

	num = 0;
	while (n / 10 != 0)
	{
		n /= 10;
		num++;
	}
	return (num + 1);
}

static char	*ft_putnums(char *sn, int n, int num)
{
	if (n < 0)
	{
		sn[0] = '-';
		sn[num] = '\0';
		num -= 1;
		n *= -1;
		while (num > 0)
		{
			sn[num] = (n % 10) + 48;
			n /= 10;
			num--;
		}
	}
	else
	{
		sn[num] = '\0';
		num -= 1;
		while (num >= 0)
		{
			sn[num] = (n % 10) + 48;
			n /= 10;
			num--;
		}
	}
	return (sn);
}

char	*ft_itoa(int n)
{
	int		num;
	int		d;
	char	*sn;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	d = n;
	if (n < 0)
		d *= -1;
	num = ft_numdigit(d);
	if (n < 0)
		num += 1;
	sn = (char *)malloc(sizeof(char) * num +1);
	if (!sn)
		return (0);
	sn = ft_putnums(sn, n, num);
	return (sn);
}
