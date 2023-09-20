NAME = fractol

CFLAGS = -Wall -Wextra -Werror
LIBMLX = MLX42
HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
#LIBS = "MLX42/build/libmlx42.a"
LIBFT = "libft/libft.a"
SRC = $(shell find ./src -iname "*.c")

OBJ = $(SRC:.c=.o)

all:	libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ)
		make -C libft
		@$(CC) $(SRC) $(LIBS) $(LIBFT) $(HEADERS) -o $(NAME)
		make clean

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
		make clean  -C libft
		rm -f ${OBJ}

fclean:	clean
		make fclean -C libft
		rm -f $(NAME)

re:	clean all
