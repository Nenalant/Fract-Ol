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


#include <fractol.h>

void	put_image(t_env *e, int x, int y)
{
	if (x <= 0 || x >= e->win_y || y <= 0 || y >= e->win_x)
		return ;
	*(e->img.data + x * e->img.size_line + e->img.bpp / 8 * y) = e->b;
	*(e->img.data + x * e->img.size_line + e->img.bpp / 8 * y + 1) = e->g;
	*(e->img.data + x * e->img.size_line + e->img.bpp / 8 * y + 2) = e->r;
}

void	init_struct(t_env *e)
{
	if (!(e->mlx = mlx_init()))
	{
		PUT_STRING(2, "error environement");
		exit(0);
	}
	e->win_x = WIDTH;
	e->win_y = HEIGHT;
	e->img.win = mlx_new_window(e->mlx, e->win_x, e->win_y, "FRACT'OL");
	e->img.img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->img.data = mlx_get_data_addr(e->img.img, &e->img.bpp, &e->img.size_line, &e->img.endian);
}

int		put_img_to_win(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->img.win, e->img.img, 0, 0);
	return(0);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while(s[i])
		++i;
	return(i);
}

int		key_hook(int keycode, t_env *e)
{
	printf("%i\n", keycode);
	(void)e;
	if (keycode == 53)
		exit (0);
	return (0);
}

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
	e->b = 	f->i * (255 & 0b11000000);
	put_image(e, x, y);
}

void	init_formul(t_fr *f)
{
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->i_max = 150;
}

void	init_formul_2(t_env *e, t_fr *f, t_img img)
{
	f->i = 0;	
	e->img.move_x = 0;
	e->img.move_y = 0;
	e->img.zoom = 1;
	e->img.cre = 0;
	e->img.cim = 0;
	f->z_r = img.cre;
	f->z_i = img.cim;
	f->img_x = (f->x2 - f->x1) * e->img.zoom;
	f->img_y = (f->y2 - f->y1) * e->img.zoom;
}

void	mandel(t_env *e, t_fr f, int x, int y, t_img img)
{
	f.c_r = 2 * (x - e->win_x / 2) / (0.5 * e->img.zoom * e->win_x) + img.move_x;
	f.c_i = (y - e->win_y / 2) / (0.5 * e->img.zoom * e->win_y) + img.move_y;

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

// void	julia(t_env *e, int x, int y, t_img img)
// {
// 	t_fr 	f;
// 	init_formul(&f);
// 	init_formul_2(e, &f, x, y);

// 	while (f.i < f.i_max)
// 	{
// 		f.oldr = f.z_r;
// 		f.oldi = f.z_i;
// 		f.z_r = (f.oldr * f.oldr - f.oldi * f.oldi);
// 		f.z_i = (2 * f.oldr * f.oldi);
// 		if ((f.z_r * f.z_r + f.z_i * f.z_i) > 4)
// 			break ;
// 		f.i++;
// 	}
// 	if (f.i != f.i_max)
// 		init_color(e, &f, y, x);
// 	else
// 		init_color_black(e, y, x);
// }


void	draw(t_env *e, t_fr *f)
{
	// printf("5-0\n");
	int		y;
	int		x;
	e->r = 0xFF;
	e->g = 0x66;
	e->b = 0xFF;

			// printf("5-1\n");
	y = 0;
	while (y < e->win_x)
	{
		x = 0;
		while (x < e->win_y)
		{
			// printf("5-2\n");
			mandel(e, *f, y, x, e->img);
	 		x++;
	 	}
		y++;
	}
				// printf("5-3\n");

}

void	mouse_more(t_env *e, int x, int y)
{
	double	h;

	(void)x;
	(void)y;
	printf("zoom == %d\n", e->img.zoom);
	h = 0.1;
	if (e->img.zoom < 7)
		e->img.zoom += 1;
	// f->x1 = x - h;
	// f->x2 = x + h;
	// f->y1 = y - h;
	// f->y2 = y + h;
	//  // f->i_max = 300;
	// e->img.cre = x;
	// e->img.cim = y;
	put_img_to_win(e);
}

void	mouse_less(t_env *e, int x, int y)
{
	double	h;

	(void)x;
	(void)y;
	printf("zoom == %d\n", e->img.zoom);
	h = 0.1;
	if (e->img.zoom > 1)
		e->img.zoom -= 1;
	// f->x1 = x - h;
	// f->x2 = x + h;
	// f->y1 = y - h;
	// f->y2 = y + h;
	// f->i_max = 300;
	put_img_to_win(e);
}

int		mouse_hook(int key, int x, int y, t_env *e)
{
	printf("%d / %d / %d\n", key, x, y);
	if (key == 4)
	{
		// e->img.move_y -= -1;
		mouse_more(e, x, y);
	}
	if (key == 5)
	{
		// e->img.move_y -= -1;
		mouse_less(e, x, y);
	}
	// e->f.z_r = x;
	// e->f.z_i = y;
	draw(e, &e->f);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	init_formul(&e.f);
	init_formul_2(&e, &e.f, e.img);
	if (ac == 3 || ac == 2)
	{
		init_struct(&e);
		mlx_mouse_hook(e.img.win, mouse_hook, &e);
		draw(&e, &e.f);
		mlx_hook(e.img.win, 2, 3, key_hook, &e);
		put_img_to_win(&e);
		// mlx_expose_hook(e.win, put_img_to_win, &e);
		mlx_loop(e.mlx);
	}
	else
	{
		PUT_STRING(2, "Error\nUsage: ");
		write(2, av[0], ft_strlen(av[0]));
		PUT_STRING(2, " Julia, Mandelbrot or Modulo");
		PUT_STRING(2, "\n");
	}
	return (0);
}