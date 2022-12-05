# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaatar <bbaatar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 11:01:46 by bbaatar           #+#    #+#              #
#    Updated: 2022/10/11 11:01:47 by bbaatar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
SRCS = ./tester/map_tester.cpp

OBJS	= $(SRCS:.cpp=.o)
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -D NS=ft
RM		= rm -f

all		:	$(NAME)

.cpp.o	:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY	: all clean fclean re

