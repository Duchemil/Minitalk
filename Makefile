CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
SRCDIR = ./printf-main
SRCFILES = ft_nbr.c ft_printf.c ft_word.c
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))

SERVER_SRCS = server.c utils.c
CLIENT_SRCS = client.c utils.c
HEADERS = minitalk.h
SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRCS) $(HEADERS) $(SRCS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SRCS) $(SRCS)

$(CLIENT): $(CLIENT_SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_SRCS)

clean:
	rm -f $(SERVER) $(CLIENT)

fclean: clean

re: fclean all
