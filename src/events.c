/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:21:05 by relkassm          #+#    #+#             */
/*   Updated: 2019/12/02 15:21:06 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press(int button, int x, int y, t_win *w)
{
	if (button == 4 && w->iter > 2)
	{
		zoom(w, x, y, 0.9);
		w->iter -= 1;
	}
	else if (button == 5)
	{
		zoom(w, x, y, 1 / 0.9);
		w->iter += 1;
	}
	else
		return (0);
	if (w->map == 1)
		julia(w);
	else if (w->map == 2)
		mandelbrot(w);
	else if (w->map == 3)
		burningship(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
	return (0);
}

int		mouse_move(int x, int y, t_win *w)
{
	if (x >= 0 && x <= 800 && y >= 0 && y <= 800\
	&& w->map == 1 && (w->julia_pause % 2) == 0)
	{
		w->julx = ((long double)x / 800) * 2 - 1;
		w->july = ((long double)y / 800) * 2 - 1;
		julia(w);
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
	}
	return (0);
}

int		keypress(int key, t_win *w)
{
	if (key == 124)
		w->x0 += 20;
	else if (key == 125)
		w->y0 += 20;
	else if (key == 123)
		w->x0 -= 20;
	else if (key == 126)
		w->y0 -= 20;
	else if (key == 7)
		init(w->map);
	else if (key == 15)
		w->red += 10;
	else if (key == 5)
		w->green += 10;
	else if (key == 11)
		w->blue += 10;
	else if (key == 35)
		w->julia_pause += 1;
	else if (key == 53)
		exit(0);
	else
		return (0);
	fract(w);
	return (0);
}

void	fract(t_win *w)
{
	if (w->map == 1)
		julia(w);
	else if (w->map == 2)
		mandelbrot(w);
	else if (w->map == 3)
		burningship(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
}
