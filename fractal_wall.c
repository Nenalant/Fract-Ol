/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanteri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:19:07 by alanteri          #+#    #+#             */
/*   Updated: 2016/12/07 19:19:09 by alanteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_wall(t_env *e, t_fr f, int x, int y)
{
	f.c_r = 2 * (x - e->win_x / 2)
		/ (0.5 * e->img.zoom * e->win_x) + e->img.move_x;
	f.c_i = (y - e->win_y / 2) / (0.5 * e->img.zoom * e->win_y) + e->img.move_y;
	while (f.i < f.i_max)
	{
		f.oldr = f.z_r;
		f.oldi = f.z_i;
		f.z_r = pow(f.oldr, 3) - (f.oldr * f.oldi * f.oldi) + f.c_r;
		f.z_i = (3 * f.oldr * f.oldr * f.oldi) - pow(f.oldi, 3) + f.c_i;
		if ((f.z_r * f.z_r + f.z_i * f.z_i) > 4)
			break ;
		f.i++;
	}
	if (f.i != f.i_max)
		init_color(e, &f, y, x);
	else
		init_color_black(e, y, x);
}
