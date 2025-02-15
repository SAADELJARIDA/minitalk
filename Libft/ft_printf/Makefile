# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 20:13:36 by sel-jari          #+#    #+#              #
#    Updated: 2024/11/07 20:49:48 by sel-jari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCF = ft_printf_conversion.c ft_printf_p.c ft_printf_xXl.c ft_printf_cs.c ft_printf.c ft_printf_idu.c

NAME = libftprintf.a

OBJF = ${SRCF:.c=.o}

CC = cc

FLAGS = -Wall -Wall -Werror

LIB = ar rcs

RM = rm -f

all: ${NAME}

${NAME}: ${OBJF}
	${LIB} ${NAME} ${OBJF}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJF}
fclean:
	${RM} ${NAME} ${OBJF}
re: fclean all
