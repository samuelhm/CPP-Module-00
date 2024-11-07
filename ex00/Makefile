# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 01:23:11 by shurtado          #+#    #+#              #
#    Updated: 2024/11/07 01:51:27 by shurtado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Config
CC = c++
TARGET = megaphone
CFLAGS = -Wall -Wextra -Werror -std=c++98
DFLAGS = -fsanitize=address

# Directory
SRC = megaphone.cpp

# Main entrance
all: $(TARGET)

# Compile Binary
$(TARGET): $(SRC) Makefile
	$(CC) $(CFLAGS) $(DFLAGS) $(SRC) -o $(TARGET)

clean: 

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re