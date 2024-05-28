# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 12:06:37 by sekeskin          #+#    #+#              #
#    Updated: 2024/05/06 12:06:45 by sekeskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRC				=	source/map_control.c	\
					source/path_finding.c	\
					source/play_game.c	\
					source/so_long.c	\
					source/utils.c	\

LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH		=	minilibx
OBJ				=	$(SRC:.c=.o)
all:	$(NAME)

$(NAME): mlx $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx

$(LIBFT):
	make -C $(LIBFT_PATH) all

mlx:
	make -C $(MINILIBX_PATH) all

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean


fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(MINILIBX_PATH) clean
	$(RM) $(NAME)

re:					fclean all

.PHONY:	all clean fclean re libft
.SECONDARY:	mlx
