# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 11:09:45 by sekeskin          #+#    #+#              #
#    Updated: 2023/12/26 12:52:45 by sekeskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.c	\
ft_isdigit.c	\
ft_isalnum.c	\
ft_isascii.c	\
ft_isprint.c	\
ft_toupper.c	\
ft_tolower.c	\
ft_strncmp.c	\
ft_memcmp.c		\
ft_atoi.c		\
ft_memset.c		\
ft_bzero.c		\
ft_memcpy.c		\
ft_memmove.c	\
ft_memchr.c		\
ft_calloc.c		\
ft_striteri.c	\
ft_putchar_fd.c	\
ft_putstr_fd.c	\
ft_putendl_fd.c	\
ft_putnbr_fd.c	\
ft_strchr.c		\
ft_strrchr.c	\
ft_strnstr.c	\
ft_strdup.c		\
ft_substr.c		\
ft_strjoin.c	\
ft_strtrim.c	\
ft_strmapi.c	\
ft_itoa.c		\
ft_split.c		\
ft_strlen.c		\
ft_strlcpy.c	\
ft_strlcat.c	\
ft_printf.c		\
ft_printf_utils.c

OBJ = $(SRC:.c=.o)

GREEN   = \033[32;1m
RED     = \033[31;49;1m
YELLOW  = \033[33;49;1m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\n	$(GREEN) $@ built $(RESET)\n"

clean:
	@/bin/rm -f  $(OBJ)
	@echo "\n	$(YELLOW) object files removed $(RESET)\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@echo "	$(YELLOW) static library removed $(RESET)\n"

re: fclean all

.PHONY: all bonus clean fclean re