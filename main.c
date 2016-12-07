/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanteri <alanteri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:59:12 by alanteri          #+#    #+#             */
/*   Updated: 2015/12/11 19:59:16 by alanteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_fractal(t_env *e, t_fr f, int y, int x)
{
	if ((ft_strcmp(e->name, "mandelbrot")) == 0)
		mandel(e, f, y, x);
	else if ((ft_strcmp(e->name, "burning_ship")) == 0)
		burning_ship(e, f, y, x);
	else if ((ft_strcmp(e->name, "burning_ship_circular")) == 0)
		burning_ship_circular(e, f, y, x);
	else if ((ft_strcmp(e->name, "julia")) == 0)
		julia(e, f, y, x);
	else if ((ft_strcmp(e->name, "julia_circular")) == 0)
		julia_circular(e, f, y, x);
	else if ((ft_strcmp(e->name, "fractal_wall")) == 0)
		fractal_wall(e, f, y, x);
	else
	{
		PUT_STRING(2, "ERROR\nUsage: ./fractol mandelbrot, burning_ship, ");
		PUT_STRING(2, "burning_ship_circular, julia, julia_circular ");
		PUT_STRING(2, "or fractal_wall\n");
		exit(0);
	}
}

int		red_cross(t_env *e)
{
	(void)e;
	exit(0);
	return (0);
}

void	main_error(void)
{
	PUT_STRING(2, "ERROR\nUsage: ./fractol mandelbrot, burning_ship, ");
	PUT_STRING(2, "burning_ship_circular, julia, julia_circular ");
	PUT_STRING(2, "or fractal_wall");
	PUT_STRING(2, "\n");
}

int		main(int ac, char **av)
{
	t_env	e;

	init_formules(&e, av[1]);
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") != 0
			|| ft_strcmp(av[1], "burning_ship") != 0
			|| ft_strcmp(av[1], "burning_ship_circular") != 0
			|| ft_strcmp(av[1], "julia") != 0
			|| ft_strcmp(av[1], "julia_circular") != 0
			|| ft_strcmp(av[1], "fractal_wall") != 0)
		{
			init_struct(&e);
			mlx_mouse_hook(e.img.win, mouse_hook, &e);
			mlx_hook(e.img.win, 2, 3, key_hook, &e);
			mlx_hook(e.img.win, 6, 1 << 6, mouse_motion, &e);
			mlx_hook(e.img.win, 17, 0, red_cross, &e);
			draw(&e, &e.f);
			put_img_to_win(&e);
			mlx_loop(e.mlx);
		}
	}
	else
		main_error();
	return (0);
}
