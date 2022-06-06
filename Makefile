# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 16:18:43 by jcalon            #+#    #+#              #
#    Updated: 2022/06/06 23:43:18 by crazyd           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS 	= srcs/main.c srcs/set_up.c srcs/parsing.c srcs/put_map.c srcs/bonhomme_moves.c srcs/mechant_moves.c srcs/animations.c srcs/put_stuff.c srcs/error.c

OBJS 	= ${SRCS:.c=.o}

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

INCLUDES = -I mlx_linux -I libft -I includes -I /usr/include

.c.o:
		@${CC} ${CFLAGS} ${INCLUDES} -c -o $@ $<

all: ${NAME}

${NAME}: ${OBJS}
		@echo "\033[33m----Compiling lib----"
		@make re -C libft --no-print-directory
		@make -C mlx_linux --no-print-directory
		@$(CC) $(CFLAGS) ${OBJS} -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ${INCLUDES} -o ${NAME}
		@echo "\033[32mso_long Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
		@make clean -C libft --no-print-directory
		@rm -f ${OBJS}

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)
		@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

.PHONY: all clean fclean re re_bonus bonus party