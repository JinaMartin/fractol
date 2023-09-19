NAME = fractol

FLAGS = -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit
MLX = "MLX42/build/libmlx42.a"
LIBFT = "libft/libft.a"
SRC = 	src/main.c \
		src/init.c \
		src/render.c \
		src/math_utils.c \
		src/events.c

CC = gcc

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		make -C libft
		cc $(SRC) $(MLX) $(LIBFT) $(FLAGS) -o $(NAME)
		make clean

%.o: %.c
	cc -Wall -Wextra -Werror -Imlx -c $< -o $@

all:	$(NAME)

clean:
		make clean  -C libft
		rm -f ${OBJ}

fclean:	clean
		make fclean -C libft
		rm -f $(NAME)

re:	fclean all