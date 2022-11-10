# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jhoekstr <jhoekstr@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/03 14:44:46 by jhoekstr      #+#    #+#                  #
#    Updated: 2022/11/10 18:20:01 by jhoekstr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jhoekstr <jhoekstr@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/05 15:18:40 by jhoekstr      #+#    #+#                  #
#    Updated: 2022/10/31 15:59:02 by jhoekstr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c \
	checker.c \


OBJ = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -Imlx -g -fsanitize=address

HEADERS	= -I libft

CC = gcc

LIBFT = LIBFT/libft.a


all: $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(HEADERS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(NAME) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(NAME) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libft