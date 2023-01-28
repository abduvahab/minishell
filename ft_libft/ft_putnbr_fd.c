/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:40:17 by areheman          #+#    #+#             */
/*   Updated: 2022/03/18 15:21:57 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_putnbrs(int n, int fd)
{
	char	c;

	if (n < 10)
	{
		c = 48 + n;
		ft_putchar_fd(c, fd);
	}
	else
	{
		my_putnbrs(n / 10, fd);
		c = 48 + n % 10;
		ft_putchar_fd(c, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	s;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	s = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		s = n * (-1);
	}	
	my_putnbrs(s, fd);
}
