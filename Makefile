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

NAME = ft_container
# SRCS = ./tester/stack_tester.cpp
SRCS = ./temp/iterator_tester.cpp

OBJS	= $(SRCS:.cpp=.o)
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
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

