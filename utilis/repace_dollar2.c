/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repace_dollar2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:20:53 by areheman          #+#    #+#             */
/*   Updated: 2022/10/11 17:02:11 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_value_dollar(char *ds)
{
	extern t_minish	g_minish;
	char			*vl;
	char			**ev;
	int				i;

	i = 0;
	if (!ft_strcmp(ds, "?"))
	{
		vl = ft_itoa(g_minish.statu);
		return (vl);
	}
	ev = all_env_var();
	while (ev[i] && ds[0] != '*')
	{
		if (!ft_strncmp(ds, ev[i], ft_strlen(ds)))
		{
			vl = env_get_value(g_minish.env, ev[i]);
			ft_frees(ev);
			return (vl);
		}
		i++;
	}
	ft_frees(ev);
	return (NULL);
}

int	is_dollar_write(char *s, int i)
{
	if (s[i] == '$')
	{
		if (ft_isalnum(s[i + 1]) || s[i + 1] == '*' || s[i + 1] == '?')
			return (1);
	}
	return (0);
}
