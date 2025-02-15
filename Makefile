CFLAGS = -Wall -Wextra -Werror
CC = cc

SERVER_MANDA = server
CLIENT_MANDA = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
NAME = $(SERVER_MANDA) $(CLIENT_MANDA)
LIB_DIR = Libft
LIB_FILE = libft.a
LIB = $(LIB_DIR)/$(LIB_FILE)

all: $(LIB) $(NAME)

$(NAME): 

$(SERVER_MANDA):
	$(CC) $(CFLAGS) server.c $(LIB) -o $(SERVER_MANDA)

$(CLIENT_MANDA):
	$(CC) $(CFLAGS) client.c $(LIB) -o $(CLIENT_MANDA)

$(SERVER_BONUS):
	$(CC) $(CFLAGS) server_bonus.c $(LIB) -o $(SERVER_BONUS)

$(CLIENT_BONUS):
	$(CC) $(CFLAGS) client_bonus.c $(LIB) -o $(CLIENT_BONUS)
	
bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	rm -f *.o
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -f $(SERVER_MANDA) $(CLIENT_MANDA) $(SERVER_BONUS) $(CLIENT_BONUS)
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
