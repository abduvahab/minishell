# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 12:49:05 by areheman          #+#    #+#              #
#    Updated: 2022/10/13 15:20:43 by areheman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror  -g3 -fsanitize=address
CC = gcc
LDFLAGS	= -L./ft_libft -L/Users/areheman/.brew/opt/readline/lib -lft  -lreadline
CPPFLAGS = -I./includes  -I./libft/includes  -I/Users/areheman/.brew/opt/readline/include

SRCS= main.c ft_signal.c env_utilise.c exc_cmd.c my_execve.c \
		utilis/utilise1.c \
		utilis/utilise2.c \
		utilis/utilise3.c \
		utilis/replace_dollar.c \
		utilis/repace_dollar2.c \
		utilis/rm_quot_dollar.c \
		checks/is_end_pipe.c \
		checks/check_line2.c \
		checks/check_line.c \
		redir/creat_fork.c \
		redir/exec_order.c \
		redir/exec_redir.c \
		redir/redir_utilise.c \
		redir/redir_utilise2.c \
		pipe/exec_pipe.c \
		pipe/pipe_utilise2.c \
		pipe/pipe_utilise3.c \
		pipe/pipe_utilis.c \
		builts/cd.c \
		builts/export.c \
		builts/expor_utilise.c \
		builts/unset.c \
		builts/unset_utilise.c \
		builts/exc_exit.c \
		builts/echo.c \
		builts/pwd.c \
		builts/env.c \
		builts/exit_utilise.c


OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) all -C ft_libft
		$(CC) $(CFLAGS) $(LDFLAGS) ft_libft/libft.a -o $@ $^

.c.o : 
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o ${<:.c=.o}  

clean : 
		$(MAKE) clean -C ft_libft
		rm -rf $(OBJS)

fclean : clean
		$(MAKE) fclean -C ft_libft
		rm -rf $(NAME)

re : fclean all 

.PHONY : all clear fclean re