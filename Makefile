# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 19:26:17 by apavlopo          #+#    #+#              #
#    Updated: 2025/01/30 19:26:30 by apavlopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft/include
LIBFT = ./libft/libft.a

# Source Files
SRCS_SERVER = src/server.c
SRCS_CLIENT = src/client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Executable Names
NAME_SERVER = server
NAME_CLIENT = client

# Build all (both server and client)
all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

# Compile Libft
$(LIBFT):
	$(MAKE) -C libft

# Compile Server
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

# Compile client
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	$(MAKE) -C libft clean

fclean:	clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C libft fclean

re:	fclean all

.PHONY: all clean fclean re
