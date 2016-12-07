/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanteri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:19:20 by alanteri          #+#    #+#             */
/*   Updated: 2016/12/07 19:19:29 by alanteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_more(t_env *e, int x, int y)
{
	double	h;

	(void)x;
	(void)y;
	h = 0.1;
	e->img.zoom += 1;
}

void	mouse_less(t_env *e, int x, int y)
{
	double	h;

	(void)x;
	(void)y;
	h = 0.1;
	if (e->img.zoom > 1)
		e->img.zoom -= 1;
}

int		key_hook(int key, t_env *e)
{
	if (key == 53)
		exit(0);
	else if (key == KEY_RIGHT)
		e->img.move_x += 0.1;
	else if (key == KEY_UP)
		e->img.move_y -= 0.1;
	else if (key == KEY_LEFT)
		e->img.move_x -= 0.1;
	else if (key == KEY_DOWN)
		e->img.move_y += 0.1;
	else if (key == KEY_PLUS)
		++e->f.i_max;
	else if (key == KEY_MINUS && e->f.i_max > 2)
		--e->f.i_max;
	draw(e, &e->f);
	put_img_to_win(e);
	return (0);
}

int		mouse_hook(int key, int x, int y, t_env *e)
{
	if (key == 4)
		mouse_more(e, x, y);
	else if (key == 5)
		mouse_less(e, x, y);
	draw(e, &e->f);
	put_img_to_win(e);
	return (0);
}

int		mouse_motion(int x, int y, t_env *e)
{
	if (e->old_x > x)
		e->img.cre -= 0.008;
	else if (e->old_x < x)
		e->img.cre += 0.008;
	if (e->old_y > y)
		e->img.cim -= 0.008;
	else if (e->old_y < y)
		e->img.cim += 0.008;
	e->old_x = x;
	e->old_y = y;
	draw(e, &e->f);
	put_img_to_win(e);
	return (0);
}
