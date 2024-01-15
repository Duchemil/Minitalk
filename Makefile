CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SERVER_SRCS = src/server.c src/utils.c src/ft_nbr.c src/ft_printf.c src/ft_word.c
CLIENT_SRCS = src/client.c src/utils.c src/ft_nbr.c src/ft_printf.c src/ft_word.c
BONUS_SERVER_SRCS = bonus/server.c bonus/utils.c bonus/ft_nbr.c bonus/ft_printf.c bonus/ft_word.c
BONUS_CLIENT_SRCS = bonus/client.c bonus/utils.c bonus/ft_nbr.c bonus/ft_printf.c bonus/ft_word.c
HEADER = src/minitalk.h
BONUS_HEADER = bonus/minitalk.h
SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRCS) $(HEADER)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SRCS)

$(CLIENT): $(CLIENT_SRCS) $(HEADER)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_SRCS)

bonus: $(BONUS_SERVER_SRCS) $(BONUS_CLIENT_SRCS) $(BONUS_HEADER)
	$(CC) $(CFLAGS) -o $(SERVER) $(BONUS_SERVER_SRCS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(BONUS_CLIENT_SRCS)

clean:
	rm -f $(SERVER) $(CLIENT)

fclean: clean

re: fclean all
