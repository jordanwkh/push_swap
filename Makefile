# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jhoekstr <jhoekstr@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/05 15:18:40 by jhoekstr      #+#    #+#                  #
#    Updated: 2022/11/28 18:22:59 by jhoekstr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c \
	checker.c \


OBJ = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

HEADERS	= -I libft

CC = gcc
RM = rm -rf

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all, clean, fclean, re, libft

all: $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(HEADERS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all