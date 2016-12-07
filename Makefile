NAME = fractol

SRC = main.c \
		burning_ship.c \
		draw.c \
		event.c \
		fractal_wall.c \
		ft.c \
		init_func.c \
		julia.c \
		mandelbrot.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I./
LFLAGS = -framework OpenGL -framework Appkit

MINILIBX = -I./minilibx_macos minilibx_macos/libmlx.a

all: mlx $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(LFLAGS) $(MINILIBX) -o $@ $^

%.o: %.c
	gcc $(FLAGS) -c $(INC) $< -o $@

mlx:
	@make -C minilibx_macos/

clean:
	@rm $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make -C minilibx_macos/ clean

re: fclean all

.PHONY: clean
