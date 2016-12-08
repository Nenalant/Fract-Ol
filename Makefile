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
	@gcc $(FLAGS) $(LFLAGS) $(MINILIBX) -o $@ $^
	@echo "COMPILATION DONE"

%.o: %.c
	@gcc $(FLAGS) -c $(INC) $< -o $@

mlx:
	@make -C minilibx_macos/
	@echo "MLX COMPILATED"

clean:
	@rm -f $(OBJ)
	@echo "CLEAN DONE"

fclean: clean
	@rm -f $(NAME)
	@make -C minilibx_macos/ clean
	@echo "FCLEAN DONE"

re: fclean all

.PHONY: all mlx clean fclean re
