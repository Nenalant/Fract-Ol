/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanteri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:17:33 by alanteri          #+#    #+#             */
/*   Updated: 2016/12/07 19:17:34 by alanteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_struct(t_env *e)
{
	if (!(e->mlx = mlx_init()))
	{
		PUT_STRING(2, "error environement");
		exit(0);
	}
	e->win_x = WIDTH;
	e->win_y = HEIGHT;
	e->old_x = 0;
	e->old_y = 0;
	e->img.win = mlx_new_window(e->mlx, e->win_x, e->win_y, "FRACT'OL");
	e->img.img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->img.data = mlx_get_data_addr(e->img.img, &e->img.bpp, &e->img.size_line,
		&e->img.endian);
}

void	init_formules(t_env *e, char *av)
{
	e->name = av;
	init_formul_mandel_and_bs(&e->f);
	init_formul_mandel_and_bs_2(e, &e->f);
	init_formul_julia(&e->f);
	init_formul_julia_2(e, &e->f);
}
