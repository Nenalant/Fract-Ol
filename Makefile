
NAME = fractol

SCR = main.c

FLAGS = -Wall -Wextra -Werror -I./
LFLAGS = -framework OpenGL -framework Appkit

MINILIBX = -I./minilibx_macos minilibx_macos/libmlx.a

all: $(MINILIBX) $(NAME)

$(NAME):
	cc $(FLAGS) $(LFLAGS) $(MINILIBX) $(SCR) -o $(NAME)

$(MINILIBX):
	@make -C minilibx_macos/

clean:
	@make -C minilibx_macos/ clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
