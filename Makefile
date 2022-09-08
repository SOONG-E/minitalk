# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 15:51:31 by yujelee           #+#    #+#              #
#    Updated: 2022/09/09 01:21:04 by yujelee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = 	libft/ft_atoi.c		\
		libft/ft_putnbr.c

C_SRCS = client.c

S_SRCS = server.c

NAME = client

OBJS = $(SRCS:.c=.o)
C_OBJS = $(C_SRCS:.c=.o)
S_OBJS = $(S_SRCS:.c=.o)

RM = rm -rf

all : $(NAME) server

$(NAME) : $(OBJS) $(C_OBJS)
	$(CC) $(OBJS) $(C_OBJS) -o $@

server : $(OBJS) $(S_OBJS)
	$(CC) $(OBJS) $(S_OBJS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(C_OBJS) $(S_OBJS) $(OBJS)

fclean : clean
	$(RM) $(NAME) server
	
re : 
	make fclean
	make all

.PHONY: all clean fclean re
