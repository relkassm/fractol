/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:38:35 by relkassm          #+#    #+#             */
/*   Updated: 2019/11/28 16:19:58 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "julia") == 0 || ft_strcmp(av[1], "1") == 0)
			init(1);
		else if (ft_strcmp(av[1], "mandelbrot") == 0 ||\
			ft_strcmp(av[1], "2") == 0)
			init(2);
		else if (ft_strcmp(av[1], "burning ship") == 0 ||\
			ft_strcmp(av[1], "3") == 0)
			init(3);
		else
		{
			ft_putendl("Chose one of the following types of fractals:\
			\n 1 - Julia\n 2 - Mandelbrot\n 3 - Burning Ship");
		}
	}
	else
		ft_putendl("usage :  ./fracol [Fractal's Type]\
		\n 1 - Julia\n 2 - Mandelbrot\n 3 - Burning Ship");
	return (0);
}

void		init(int n)
{
	t_win	w;

	w.map = n;
	w.height = 800;
	w.iter = 10;
	w.x0 = 0;
	w.y0 = 0;
	w.start_x = 0;
	w.start_y = 0;
	w.end_x = 800;
	w.end_y = 800;
	w.s2 = -2;
	w.e2 = 2;
	w.julia_pause = 0;
	w.julx = 0;
	w.july = 0;
	w.red = 5;
	w.green = 5;
	w.blue = 5;
	mlx_start(n, w);
}

void		mlx_start(int n, t_win w)
{
	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.height, w.height, "Fractol");
	w.img_ptr = mlx_new_image(w.mlx_ptr, w.height, w.height);
	w.img_data = mlx_get_data_addr(w.img_ptr, &w.x, &w.size_line, &w.end);
	mlx_hook(w.win_ptr, 2, 0, keypress, &w);
	mlx_hook(w.win_ptr, 4, 0, mouse_press, &w);
	mlx_hook(w.win_ptr, 6, 0, mouse_move, &w);
	if (n == 1)
		julia(&w);
	if (n == 2)
		mandelbrot(&w);
	if (n == 3)
		burningship(&w);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img_ptr, 0, 0);
	mlx_loop(w.mlx_ptr);
}

void		putimagein(int x, int y, int color, t_win *w)
{
	int i;

	if (x < 800 && y < 800 && x > 0 && y > 0)
	{
		i = (x * w->x / 8) + (y * w->size_line);
		w->img_data[i] = color * w->blue;
		w->img_data[++i] = color * w->green;
		w->img_data[++i] = color * w->red;
		w->img_data[++i] = 0;
	}
}
