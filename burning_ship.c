/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanteri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:18:46 by alanteri          #+#    #+#             */
/*   Updated: 2016/12/07 19:18:47 by alanteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(t_env *e, t_fr f, int x, int y)
{
	f.c_r = 2 * (x - e->win_x / 2)
		/ (0.5 * e->img.zoom * e->win_x) + e->img.move_x;
	f.c_i = (y - e->win_y / 2) / (0.5 * e->img.zoom * e->win_y) + e->img.move_y;
	while (f.i < f.i_max)
	{
		f.oldr = f.z_r;
		f.oldi = f.z_i;
		f.z_r = (f.oldr * f.oldr - f.oldi * f.oldi) + f.c_r;
		f.z_i = fabs(2 * f.oldr * f.oldi) + f.c_i;
		if ((f.z_r * f.z_r + f.z_i * f.z_i) > 4)
			break ;
		f.i++;
	}
	if (f.i != f.i_max)
		init_color(e, &f, y, x);
	else
		init_color_black(e, y, x);
}

void	burning_ship_circular(t_env *e, t_fr f, int x, int y)
{
	f.c_r = 2 * (x - e->win_x / 2)
		/ (0.5 * e->img.zoom * e->win_x) + e->img.move_x;
	f.c_i = 2 * (y - e->win_y / 2)
		/ (0.5 * e->img.zoom * e->win_y) + e->img.move_y;
	while (f.i < f.i_max)
	{
		f.oldr = f.z_r;
		f.oldi = f.z_i;
		f.z_r = (f.oldr * f.oldr - f.oldi * f.oldi) + f.c_r;
		f.z_i = fabs(2 * f.oldr * f.oldi) + f.c_i;
		if ((f.z_r * f.z_r + f.z_i * f.z_i) > 4)
			break ;
		f.i++;
	}
	if (f.i != f.i_max)
		init_color(e, &f, y, x);
	else
		init_color_black(e, y, x);
}
