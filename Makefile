# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 16:18:43 by jcalon            #+#    #+#              #
#    Updated: 2022/06/07 14:07:52 by jcalon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
NAME_BONUS = so_long_bonus

SRCS 	= srcs/so_long.c srcs/set_up.c srcs/parsing.c srcs/put_map.c srcs/bonhomme.c srcs/put_stuff.c srcs/error.c
SRCSB 	= srcsb/so_long_bonus.c srcsb/set_up_bonus.c srcsb/parsing_bonus.c srcsb/put_map_bonus.c srcsb/bonhomme_moves_bonus.c srcsb/mechant_moves_bonus.c srcsb/animations_bonus.c srcsb/put_stuff_bonus.c srcsb/error_bonus.c

OBJS 	= ${SRCS:.c=.o}
OBJSB 	= ${SRCSB:.c=.o}

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

INCLUDES = -I mlx_linux -I libft -I includes -I usr/include

.c.o:
		@${CC} ${CFLAGS} ${INCLUDES} -c -o $@ $<

all: 	${NAME}

${NAME}: ${OBJS}
		@echo "\033[33m----Compiling lib----"
		@make re -C libft --no-print-directory
		@make -C mlx_linux --no-print-directory
		@$(CC) $(CFLAGS) ${OBJS} -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ${INCLUDES} -o ${NAME}
		@echo "\033[32mso_long Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

${NAME_BONUS}: ${OBJSB}
		@echo "\033[33m----Compiling lib----"
		@make re -C libft --no-print-directory
		@make -C mlx_linux --no-print-directory
		@$(CC) $(CFLAGS) ${OBJSB} -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ${INCLUDES} -o ${NAME_BONUS}
		@echo "\033[32mso_long Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
		@make clean -C libft --no-print-directory
		@rm -f ${OBJS}
		@rm -f ${OBJSB}

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)
		@rm -f $(NAME_BONUS)
		@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:		fclean all

bonus: ${NAME_BONUS}

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus bonus