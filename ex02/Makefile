# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 01:23:11 by shurtado          #+#    #+#              #
#    Updated: 2025/02/02 21:04:56 by shurtado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	account
CC			=	c++
CPPFLAGS	=	-g -Wall -Werror -Wextra -std=c++98 -MMD -MP

CLASSES		=	Account

SRC			=	$(addprefix src/, $(foreach class, $(CLASSES), $(class)/$(class).cpp) tests.cpp)

OBJS		=	$(SRC:%.cpp=obj/%.o)
DEPS		=	$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
