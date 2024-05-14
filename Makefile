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
BONUS_SERVER = server_bonus
BONUS_CLIENT = client_bonus

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRCS) $(HEADER)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SRCS)

$(CLIENT): $(CLIENT_SRCS) $(HEADER)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_SRCS)

bonus: $(BONUS_SERVER) $(BONUS_CLIENT)

$(BONUS_SERVER): $(BONUS_SERVER_SRCS) $(BONUS_HEADER)
	$(CC) $(CFLAGS) -o $(BONUS_SERVER) $(BONUS_SERVER_SRCS)

$(BONUS_CLIENT): $(BONUS_CLIENT_SRCS) $(BONUS_HEADER)
	$(CC) $(CFLAGS) -o $(BONUS_CLIENT) $(BONUS_CLIENT_SRCS)

clean:
	rm -f $(SERVER) $(CLIENT) $(BONUS_SERVER) $(BONUS_CLIENT)

fclean: clean

re: fclean all

.PHONY: all bonus clean fclean re
