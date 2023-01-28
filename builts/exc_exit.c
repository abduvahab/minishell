/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:38:41 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 11:09:29 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

long long	ft_atoi_exit(const char *str, int i, int *pbm)
{
	int			j;
	long		neg;
	long long	sum;

	neg = 1;
	sum = 0;
	j = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] && (ft_isspace(str[i]) || str[i] == '0'))
		i++;
	while (str[i] >= '0' && str[i] <= '9' && ++j)
	{
		sum = (sum * 10) + (str[i] - 48);
		if (((i == 18 && neg == 1) && (str[i] > '7' && str[i] <= '9'))
			|| ((i == 19 && neg == -1) && (str[i] == '9')))
			*pbm = 1;
		i++;
	}
	while (str[i++])
		j++;
	if ((j > 19 && neg == 1) || (j > 20 && neg == -1))
		*pbm = 1;
	return (sum * neg);
}

void	is_one_arg(char **s)
{
	extern t_minish	g_minish;
	long long		code;
	int				n;

	n = 255;
	if (!is_numeric(*s))
		printf("exit: %s: numeric argument required\n", *s);
	else
	{
		n = 0;
		code = ft_atoi_exit(*s, 0, &n);
		if (n == 1)
			printf("exit: %s :numeric argument required\n", *s);
		else
		{
			n = code % 256;
			printf("exit\n");
		}
	}
	free_minish(g_minish);
	ft_frees(s);
	exit (n);
}

void	is_more_arg(char **s)
{
	extern t_minish	g_minish;

	if (is_numeric(*s))
	{
		g_minish.statu = 1;
		ft_frees(s);
		printf("exit: too many arguments\n");
		return ;
	}
	else
	{
		free_minish(g_minish);
		printf("exit\n");
		printf("exit: %s: numeric argument required\n", *s);
		ft_frees(s);
		exit (255);
	}
}

void	check_exit_str(char **s, char *tem)
{
	extern t_minish	g_minish;
	int				i;

	i = 0;
	free(tem);
	while (s[i])
		i++;
	if (i != 1)
		is_more_arg(s);
	else
		is_one_arg(s);
}

void	exc_exit(char *line)
{
	extern t_minish	g_minish;
	char			**home;
	char			*tem;
	int				n;

	if (!ft_strcmp(line, "exit"))
	{
		n = g_minish.statu;
		free_minish(g_minish);
		printf("exit\n");
		exit (n);
	}
	else
	{
		tem = line + 4;
		tem = ft_substr(tem, 0, ft_strlen(tem));
		home = ft_split(tem, ' ');
		check_exit_str(home, tem);
	}
}
