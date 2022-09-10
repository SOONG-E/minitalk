# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 15:51:31 by yujelee           #+#    #+#              #
#    Updated: 2022/09/09 22:47:48 by yujelee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = 	libft/ft_atoi.c		\
		libft/ft_putnbr.c

C_SRCS = client.c
BONUS_C_SRCS = bonus/client_bonus.c

S_SRCS = server.c
BONUS_S_SRCS = bonus/server_bonus.c

NAME = client

OBJS = $(SRCS:.c=.o)
C_OBJS = $(C_SRCS:.c=.o)
S_OBJS = $(S_SRCS:.c=.o)
BONUS_C_OBJS = $(BONUS_C_SRCS:.c=.o)
BONUS_S_OBJS = $(BONUS_S_SRCS:.c=.o)

RM = rm -rf

all : $(NAME)

bonus : $(OBJS) $(BONUS_C_OBJS) $(BONUS_S_OBJS)
	$(CC) $(OBJS) $(BONUS_C_OBJS) -o client_bonus
	$(CC) $(OBJS) $(BONUS_S_OBJS) -o server_bonus

$(NAME) : $(OBJS) $(C_OBJS) $(S_OBJS)
	$(CC) $(OBJS) $(C_OBJS) -o $@
	$(CC) $(OBJS) $(S_OBJS) -o server

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(C_OBJS) $(S_OBJS) $(OBJS) $(BONUS_C_OBJS) $(BONUS_S_OBJS)

fclean : clean
	$(RM) $(NAME) server client_bonus server_bonus
	
re : 
	make fclean
	make all

.PHONY: all clean fclean re bonus
