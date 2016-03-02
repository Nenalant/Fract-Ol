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
	*(e->data + x * e->size_line + e->bpp / 8 * y) = e->b;
	*(e->data + x * e->size_line + e->bpp / 8 * y + 1) = e->g;
	*(e->data + x * e->size_line + e->bpp / 8 * y + 2) = e->r;
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
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "FRACT'OL");
	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
}

int		put_img_to_win(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
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
	f->zoom = 1;
	f->i_max = 150;

	f->img_x = (f->x2 - f->x1) * f->zoom;
	f->img_y = (f->y2 - f->y1) * f->zoom;
}

void	init_formul_2(t_env *e, t_fr *f, int x, int y)
{
	f->c_r = 2 * (x - e->win_x / 2) / (0.5 * f->zoom * e->win_x);
	f->c_i = (y - e->win_y / 2) / (0.5 * f->zoom * e->win_y);
	f->i = 0;
	f->z_r = 0;
	f->z_i = 0;
}

void	formul(t_env *e, int x, int y)
{
	t_fr 	f;
	init_formul(&f);
	init_formul_2(e, &f, x, y);

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

void	draw(t_env *e)
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
			formul(e, y, x);
	 		x++;
	 	}
		y++;
	}
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 3 || ac == 2)
	{
		init_struct(&e);
		// mlx_mouse_hook(e.win, mouse_hook, &e);
		draw(&e);	
		mlx_hook(e.win, 2, 3, key_hook, &e);
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