# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 19:11:18 by armaxima          #+#    #+#              #
#    Updated: 2021/11/13 23:22:33 by armaxima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -MMD -Wall -Wextra -Werror

NAME = minitalk

NAME_C = client

NAME_S = server

NAME_C_B = client_bonus

NAME_S_B = server_bonus

SRC_C = client.c \
		utils_client.c

SRC_S = server.c \
		utils_server.c

SRC_C_B = client_bonus.c \
		utils_client_bonus.c

SRC_S_B = server_bonus.c \
		utils_server_bonus.c

HEADER_C = client.h

HEADER_S = server.h

HEADER_C_B = client_bonus.h

HEADER_S_B = server_bonus.h

OBJ_C = $(SRC_C:.c=.o)

OBJ_S = $(SRC_S:.c=.o)

SRC_D_C = $(SRC_C:.c=.d)

SRC_D_S = $(SRC_S:.c=.d)

OBJ_C_B = $(SRC_C_B:.c=.o)

OBJ_S_B = $(SRC_S_B:.c=.o)

SRC_D_C_B = $(SRC_C_B:.c=.d)

SRC_D_S_B = $(SRC_S_B:.c=.d)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ -I includes

all: $(NAME)

$(NAME): $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJ_C) $(HEADER_C)
	gcc $(FLAG) $(OBJ_C) -o $(NAME_C)

$(NAME_S): $(OBJ_S) $(HEADER_S)
	gcc $(FLAG) $(OBJ_S) -o $(NAME_S)

bonus: $(NAME_C_B) $(NAME_S_B)

$(NAME_C_B): $(OBJ_C_B) $(HEADER_C_B)
	gcc $(FLAG) $(OBJ_C_B) -o $(NAME_C_B)

$(NAME_S_B): $(OBJ_S_B) $(HEADER_S_B)
	gcc $(FLAG) $(OBJ_S_B) -o $(NAME_S_B)

clean:
	rm -f $(OBJ_C) $(SRC_D_C)
	rm -f $(OBJ_S) $(SRC_D_S)
	rm -f $(OBJ_C_B) $(SRC_D_C_B)
	rm -f $(OBJ_S_B) $(SRC_D_S_B)

	echo "OBJ deleted"

fclean: clean
	rm -f $(NAME_C)
	rm -f $(NAME_S)
	rm -f $(NAME_C_B)
	rm -f $(NAME_S_B)
	echo "$(NAME_C) deleted"
	echo "$(NAME_S) deleted"
	echo "$(NAME_C_B) deleted"
	echo "$(NAME_S_B) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
