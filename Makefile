# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jari <sel-jari@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 16:29:21 by sel-jari          #+#    #+#              #
#    Updated: 2024/10/28 16:32:40 by sel-jari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_MANDA = server
CLIENT_MANDA = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
NAME = $(SERVER_MANDA) $(CLIENT_MANDA)
LIB_DIR = Libft
LIB_FILE = libft.a
LIB = $(LIB_DIR)/$(LIB_FILE)
CFLAGS = -Wall -Wextra -Werror
CC = cc
LIBFT_FILES = Libft/ft_atoi.c  Libft/ft_isdigit.c Libft/libft.h
FT_PRINTF_FILES = ft_printf_conversion.c ft_printf_p.c ft_printf_xXl.c ft_printf_cs.c ft_printf.c ft_printf_idu.c ft_printf.h
FT_PRINTF_DIR = ft_printf
SRCF_FT_PRINTF = $(addprefix $(LIB_DIR)/$(FT_PRINTF_DIR)/, $(FT_PRINTF_FILES))

HEADER= minitalk.h

all: $(NAME)

$(NAME): $(HEADER) $(LIB)

$(SERVER_MANDA):  server.o
	$(CC) $(CFLAGS) server.o $(LIB) -o $(SERVER_MANDA)

$(CLIENT_MANDA):  client.o
	$(CC) $(CFLAGS) client.o $(LIB) -o $(CLIENT_MANDA)

$(SERVER_BONUS): server_bonus.o
	$(CC) $(CFLAGS) server_bonus.o $(LIB) -o $(SERVER_BONUS)

$(CLIENT_BONUS): client_bonus.o
	$(CC) $(CFLAGS) client_bonus.o $(LIB) -o $(CLIENT_BONUS)
	
bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(LIB): $(SRCF_FT_PRINTF) $(LIBFT_FILES) $(HEADER_FILES)
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
