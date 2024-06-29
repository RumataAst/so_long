# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 19:21:32 by akretov           #+#    #+#              #
#    Updated: 2024/06/01 17:28:35 by akretov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CFLAGS := -Wextra -Wall -Werror -g

LIBMLX := ./MLX
LIBFT := libft

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a -L$(LIBFT) -lft -ldl -lglfw -pthread -lm
SRCS := srcs/utils.c					\
		srcs/map_utils/map_path.c		\
		srcs/map_utils/map_utils_0.c	\
		srcs/map_utils/map_utils_1.c	\
		srcs/map_utils/map_utils_2.c	\
		srcs/map_utils/map_utils_3.c	\
		srcs/window_init/end_struct.c	\
		srcs/window_init/window_init.c	\
		srcs/window_init/window_draw.c	\
		srcs/hook/movement.c			\
		srcs/hook/hook.c				\
		srcs/run_game.c					\
		srcs/main.c
OBJS := $(SRCS:.c=.o)

all: libmlx libft $(NAME)

libmlx:
	@cmake -S $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 -ldl -lglfw -lm -lpthread

libft:
	@make -C $(LIBFT)

$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) && printf "Linking: $(NAME)\n"

clean:
	@rm -f $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libmlx libft
