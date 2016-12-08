/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanteri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:17:03 by alanteri          #+#    #+#             */
/*   Updated: 2016/12/07 19:17:05 by alanteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_formul_mandel_and_bs(t_fr *f)
{
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->i_max = 50;
}

void	init_formul_mandel_and_bs_2(t_env *e, t_fr *f)
{
	f->i = 0;
	e->img.move_x = 0;
	e->img.move_y = 0;
	e->img.zoom = 1;
	e->img.cre = 0;
	e->img.cim = 0;
	f->z_r = e->img.cre;
	f->z_i = e->img.cim;
	f->img_x = (f->x2 - f->x1) * e->img.zoom;
	f->img_y = (f->y2 - f->y1) * e->img.zoom;
}

void	mandel(t_env *e, t_fr f, int x, int y)
{
	f.c_r = 1.3 * (x - e->win_x / 2)
		/ (0.5 * e->img.zoom * e->win_x) + e->img.move_x;
	f.c_i = (y - e->win_y / 2) / (0.5 * e->img.zoom * e->win_y) + e->img.move_y;
	while (f.i < f.i_max)
	{
		f.oldr = f.z_r;
		f.oldi = f.z_i;
		f.z_r = (f.oldr * f.oldr - f.oldi * f.oldi) + f.c_r;
		f.z_i = (2 * f.oldr * f.oldi) + f.c_i;
		if ((f.z_r * f.z_r + f.z_i * f.z_i) > 4)
			break ;
		f.i++;
	}
	if (f.i != f.i_max)
		init_color(e, &f, y, x);
	else
		init_color_black(e, y, x);
}
