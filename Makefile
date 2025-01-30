NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft/include
LIBFT = ./libft/libft.a
SRC = server.c \
		client.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

