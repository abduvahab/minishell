/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:01:02 by areheman          #+#    #+#             */
/*   Updated: 2022/10/06 19:44:13 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	h_signal(int i)
{
	extern t_minish	g_minish;

	if (i == SIGINT)
	{
		g_minish.statu = 130;
		if (g_minish.sig == 0)
		{
			write(STDERR_FILENO, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
		}
		if (g_minish.sig == 1)
		{
			write(STDERR_FILENO, "\n", 1);
			g_minish.line = 0;
			printf("minishell @>");
		}
		if (g_minish.sig == 2)
			write(STDERR_FILENO, "\n", 1);
	}
}

void	ft_signal(void)
{
	signal(SIGINT, h_signal);
	signal(SIGQUIT, SIG_IGN);
}
