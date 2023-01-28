/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:59:16 by areheman          #+#    #+#             */
/*   Updated: 2022/10/13 15:19:35 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

typedef struct s_cmd
{
	char	*p_line;
	char	**cmds;
	char	*infile;
	char	*outfile;
	int		i_ap;
	int		o_ap;
	int		infd;
	int		outfd;
	int		pipe;
	pid_t	l_pd;
}			t_cmd;

typedef struct s_minish
{
	char	**env;
	char	**expo;
	char	*line;
	int		statu;
	int		sig;
}				t_minish;

void	ft_t_cmds_init(t_cmd *cmds, char *line, int n);
void	exc_cmd(char *line);
void	free_minish(t_minish minish);
int		is_built_cmd(char *s);
void	exc_built(char *cmd, t_cmd *cmds);
int		ft_add_and_delet(char **vars, char *tem, char *s);

//	env_utilise
char	**env_copy(char **s);
char	*env_get_value(char **envs, char *s);
int		env_set_value(char **envs, char *var, char *value);
int		env_set_var(char ***env, char *var, char *value);
int		env_delet_var(char ***env, char *var);

// checks
int		is_end_pipe(char *line);
char	*get_after_pipe(char *line);
int		check_line(char *line);
int		pc_redirs(char *str);
int		quotes_is_closed(char *str);

// utilise1
int		ft_strcmp(char *s1, char *s2);
int		ft_arespaces(char *str);
int		ft_isspace(char c);
int		pass_quotes(char *str, int n);
char	*ft_strjoin_str(char *var, char *value, char *mid);
//utilise2
void	ft_frees(char **s);
void	ft_free_cmds(t_cmd *cmds);
int		count_pipe(char *s);
char	**all_env_var(void);
char	*rm_quots2(char *s);
char	*ft_strjoin2(char *s1, char *s2);

// rm_quots_dollars
char	*rm_quot_dollar(char *s);
char	*rm_qouts(char *s, int *n);
int		*count_qouts(char *str);
char	*replace_dollar(char *s, int n);
char	*get_value_dollar(char *ds);
int		pass_sigle_quot(char *str, int n);
int		is_dollar_write(char *s, int i);

// ft_signal
void	ft_signal(void);

//redir
void	exec_order(t_cmd *cmds);
void	creat_fork(t_cmd *cmds);
int		my_execve(char *cmd, char *arg[]);
void	get_order(t_cmd *cmds);
int		set_fdfile_open(t_cmd *cmds);

//exec_redir.c
int		exec_redir(t_cmd *cmds);
int		exit_redir(char *s, char c);
int		is_unique_built(t_cmd *cmds);

//redir_utilise.c
int		ft_init_in_out(char ***r_s, char ***l_s, char **cmd, char *line);
int		ft_write_in(char *s, char **l_r, int *n, t_cmd *cmds);

//redir_utilise2.c
int		ft_write_out(char *s, char **r_r, int *n, t_cmd *cmds);
int		set_infile_cmds(char **l_r, int i, t_cmd *cmds);
int		set_outfile_cmds(char **r_r, int i, t_cmd *cmds);
char	*get_here_doc(char *s);

//pipe
void	exec_pipe(char *line, int n);
char	**get_pipe_strs(char *line, int n);
int		find_pipe(char *s);
void	free_p_cmds(t_cmd **p_cmds);
char	**init_cmds_str(int n);
int		exit_cat_wc(t_cmd **p_cmds);
int		all_is_cat(t_cmd **p_cmds, int n);
void	exec_wc(void);
void	exec_pipes_unique(t_cmd **p_cmds, int n);
void	exec_pipes_unique2(t_cmd **p_cmds, int n, int m);
void	exec_mix(t_cmd **p_cmds, int n, int m);
void	exec_cat(void);

//cd
void	exec_cd(char *cmd);
void	exec_unset(char *line);
void	exec_export(t_cmd *cmds);
void	exc_exit(char *line);
int		check_split_export(char *s);

// export
void	ft_add_strs(char ***bs, char *s);
void	check_export_str(char *line, int n);
void	write_export_str(char *s);
void	ft_add_strs(char ***bs, char *s);

//export_utilise
int		is_in_exprt(char *s);
int		is_in_env(char *s);
int		check_split_sxport(char *s);

// unset_utilise
void	ft_delete_str(char ***bs, char *s);
int		is_unset_env(char *s);
int		is_unset_export(char *s);

// exit_utilise
int		is_numeric(char *arg);
char	*ft_echo_joins(char **strs);
int		find_echo_str(char **tem, int i);
void	handle_export_str(char *tem);
int		is_same_str(char *s, char **vars);

//echo.c
void	exec_echo(t_cmd *cmds);
void	write_str_echo(char *s, int m, int fd);
void	exec_pwd(t_cmd *cmds);
void	exec_env(t_cmd *cmds);
char	**rm_space_echo(char *s, char **str);
int		number_strs(char *s);

#endif
