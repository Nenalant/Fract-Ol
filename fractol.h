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
# define WIDTH 600
# define HEIGHT 400
# define PUT_STRING(fd, s) (write(fd, s, sizeof(s) - 1))

typedef struct 		s_fr
{
	unsigned int	x;
	unsigned int	y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	unsigned int	zoom;
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

typedef struct		s_env
{
	int				r;
	int				g;
	int				b;
	void			*mlx;
	void			*win;
	int				win_y;
	int				win_x;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_env;

#endif
