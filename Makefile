CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SERVER_SRCS = server.c utils.c ft_nbr.c ft_printf.c ft_word.c
CLIENT_SRCS = client.c utils.c ft_nbr.c ft_printf.c ft_word.c
HEADER = minitalk.h
SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRCS) $(HEADER)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SRCS)

$(CLIENT): $(CLIENT_SRCS) $(HEADER)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_SRCS)

clean:
	rm -f $(SERVER) $(CLIENT)

fclean: clean

re: fclean all
