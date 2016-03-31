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
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 600
# define HEIGHT 400
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

typedef struct 		s_fr
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
	int				r;
	int				g;
	int				b;
	void			*mlx;
	int				win_y;
	int				win_x;
	t_img			img;
	t_fr			f;
}					t_env;

#endif
