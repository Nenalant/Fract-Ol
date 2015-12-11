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

int		put_img_to_win(void)
{
	// mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
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
	// printf("%i\n", keycode);
	if (keycode == 0)
		exit (0);
	return (0);
}
int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 3 || ac == 2)
	{
		init_struct(&e);
		mlx_hook(e.win, 2, 3, key_hook, &e);
		// mlx_mouse_hook(e.win, mouse_hook, &e);
		// put_img_to_win(&e);
		mlx_expose_hook(e.win, put_img_to_win, &e);
		mlx_loop(e.mlx);
	}
	else
	{
		PUT_STRING(2, "Error\nUsage: ");
		write(2, av[0], ft_strlen(av[0]));
		PUT_STRING(2, "\n");
	}
	return (0);
}