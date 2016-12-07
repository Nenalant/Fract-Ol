/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanteri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:16:32 by alanteri          #+#    #+#             */
/*   Updated: 2016/12/07 19:16:45 by alanteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color_black(t_env *e, int x, int y)
{
	e->r = (255 & 0b00001100) >> 2;
	e->g = (255 & 0b00110000) >> 4;
	e->b = (255 & 0b11000000) >> 6;
	put_image(e, x, y);
}

void	init_color(t_env *e, t_fr *f, int x, int y)
{
	e->r = f->i * (255 & 0b00001100);
	e->g = f->i * (255 & 0b00110000);
	e->b = f->i * (255 & 0b11000000);
	put_image(e, x, y);
}

void	draw(t_env *e, t_fr *f)
{
	int		y;
	int		x;

	e->r = 0xFF;
	e->g = 0x66;
	e->b = 0xFF;
	y = 0;
	while (y < e->win_x)
	{
		x = 0;
		while (x < e->win_y)
		{
			choose_fractal(e, *f, y, x);
			x++;
		}
		y++;
	}
}

void	put_image(t_env *e, int x, int y)
{
	if (x <= 0 || x >= e->win_y || y <= 0 || y >= e->win_x)
		return ;
	*(e->img.data + x * e->img.size_line + e->img.bpp / 8 * y) = e->b;
	*(e->img.data + x * e->img.size_line + e->img.bpp / 8 * y + 1) = e->g;
	*(e->img.data + x * e->img.size_line + e->img.bpp / 8 * y + 2) = e->r;
}

int		put_img_to_win(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->img.win, e->img.img, 0, 0);
	return (0);
}
