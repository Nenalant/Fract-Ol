/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanteri <alanteri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:59:12 by alanteri          #+#    #+#             */
/*   Updated: 2015/12/11 19:59:16 by alanteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600
# define PUT_STRING(fd, s) (write(fd, s, sizeof(s) - 1))

# define KEY_A 0
# define KEY_B 11
# define KEY_C 8
# define KEY_D 2
# define KEY_E 14
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_I 34
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_M 46
# define KEY_N 45
# define KEY_O 31
# define KEY_P 35
# define KEY_Q 12
# define KEY_R 15
# define KEY_S 1
# define KEY_T 17
# define KEY_U 32
# define KEY_V 9
# define KEY_W 13
# define KEY_X 7
# define KEY_Y 16
# define KEY_Z 6
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25
# define KEY_0 29
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_R 15
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_M 46
# define KEY_NUM_1 83
# define KEY_NUM_2 84
# define KEY_NUM_4 86
# define KEY_NUM_5 87
# define KEY_NUM_6 88
# define KEY_NUM_7 89
# define KEY_NUM_8 91
# define KEY_NUM_9 92
# define KEY_SPACE 49

typedef struct		s_fr
{
	unsigned int	x;
	unsigned int	y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	unsigned int	img_x;
	unsigned int	img_y;
	unsigned int	i_max;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			oldr;
	double			oldi;
	unsigned int	i;
}					t_fr;

typedef	struct		s_img
{
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int	zoom;
	double			move_x;
	double			move_y;
	double			cre;
	double			cim;
}					t_img;

typedef struct		s_env
{
	char			*name;
	int				r;
	int				g;
	int				b;
	void			*mlx;
	int				win_y;
	int				win_x;
	int				old_x;
	int				old_y;
	int				val;
	t_img			img;
	t_fr			f;
}					t_env;

/*
** main
*/
void				choose_fractal(t_env *e, t_fr f, int y, int x);
int					red_cross(t_env *e);
void				main_error(void);
int					main(int ac, char **av);

/*
** ft
*/
int					ft_strlen(char *s);
int					ft_strcmp(char *s1, char *s2);

/*
** init_func
*/
void				init_struct(t_env *e);
void				init_formules(t_env *e, char *av);

/*
** mandelbrot
*/
void				init_formul_mandel_and_bs(t_fr *f);
void				init_formul_mandel_and_bs_2(t_env *e, t_fr *f);
void				mandel(t_env *e, t_fr f, int x, int y);

/*
** julia
*/
void				init_formul_julia(t_fr *f);
void				init_formul_julia_2(t_env *e, t_fr *f);
void				julia_circular(t_env *e, t_fr f, int x, int y);
void				julia(t_env *e, t_fr f, int x, int y);

/*
** burning_ship
*/
void				burning_ship(t_env *e, t_fr f, int x, int y);
void				burning_ship_circular(t_env *e, t_fr f, int x, int y);

/*
** fractal_wall
*/
void				fractal_wall(t_env *e, t_fr f, int x, int y);

/*
** draw
*/
void				init_color_black(t_env *e, int x, int y);
void				init_color(t_env *e, t_fr *f, int x, int y);
void				draw(t_env *e, t_fr *f);
void				put_image(t_env *e, int x, int y);
int					put_img_to_win(t_env *e);

/*
** event
*/
void				mouse_more(t_env *e, int x, int y);
void				mouse_less(t_env *e, int x, int y);
int					key_hook(int key, t_env *e);
int					mouse_hook(int key, int x, int y, t_env *e);
int					mouse_motion(int x, int y, t_env *e);

#endif
