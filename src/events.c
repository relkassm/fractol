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
	if (button == 4)
		w->zm += 20;
	else if (button == 5 && w->zm > 0)
		w->zm -= 20;
	ft_bzero(w->img_data, 800 * 800 * 4);
	if (w->map == 1)
		julia(w);
	else if (w->map == 2)
		mandelbrot(w);
	else if (w->map == 3)
		julia(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
	return (0);
}

int		mouse_move(int x, int y, t_win *w)
{
	//w->mousex = ((float)x / 800) * 2 - 1;
	//w->mousey = ((float)y / 800) * 2 - 1;
	if (x >= 0 && x <= 800 && y >= 0 && y <= 800 && w->map == 1)
	{
		w->julx = ((float)x / 800) * 2 - 1;
		w->july = ((float)y / 800) * 2 - 1;
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
	else if (key == 69)
		w->iter += 50;
	else if (key == 78 && w->iter > 50)
		w->iter -= 50;
	else if (key == 53)
		exit(0);
	ft_bzero(w->img_data, 800 * 800 * 4);
	if (w->map == 1)
		julia(w);
	else if (w->map == 2)
		mandelbrot(w);
	else if (w->map == 3)
		julia(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
	return (0);
}
