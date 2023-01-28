# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:28:28 by areheman          #+#    #+#              #
#    Updated: 2022/09/20 12:18:22 by areheman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC =    gcc
CFLAGS = -Wall -Wextra -Werror
AR =     ar rc
RANLIB = ranlib

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c	ft_isascii.c ft_toupper.c ft_tolower.c\
		ft_strchr.c ft_isprint.c ft_strlen.c ft_strrchr.c ft_strncmp.c ft_memset.c\
		ft_bzero.c ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_strlcpy.c\
		ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c

SRCS_ADD = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
			ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJS =$(SRCS:.c=.o) $(SRCS_ADD:.c=.o)

OBJS_BONUS =$(SRC_BONUS:.c=.o)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

		
all  :  $(NAME) 

$(NAME):$(OBJS)
		@$(AR) $(NAME) $(OBJS) 
		@$(RANLIB) $(NAME) 

bonus:${OBJS_BONUS}
		@$(AR) $(NAME) $^
		@$(RANLIB) $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME) $(bonus)

re: fclean clean all 

.PHONY:all, bonus, clean, fclean, re
