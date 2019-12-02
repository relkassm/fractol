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

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "julia") == 0 || ft_strcmp(av[1], "1") == 0)
			init(1);
		else if (ft_strcmp(av[1], "mandelbrot") == 0 || ft_strcmp(av[1], "2") == 0)
			init(2);
		else if (ft_strcmp(av[1], "yikes") == 0 || ft_strcmp(av[1], "3") == 0)
			init(3);
		else
		{
			ft_putendl("Chose one of the following types of fractals :\n 1 - Julia\n 2 - Mandelbrot\n 3 - Yikes");
		}
	}
	else
		ft_putendl("usage :  ./fracol [Fractal's Type]\n 1 - Julia\n 2 - Mandelbrot\n 3 - Yikes");
		
	return (0);
}

void	init(int n)
{
	t_win	w;
	t_map	m;

	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, 800, 800, "Fractol");
	w.img_ptr = mlx_new_image(w.mlx_ptr, 800, 800);
	w.img_data = mlx_get_data_addr(w.img_ptr, &w.x, &w.size_line, &w.end);
	draw(800, 800, &w);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img_ptr, 0, 0);
	mlx_loop(w.mlx_ptr);
}

void	putimagein(int x, int y, int color, t_win *w)
{
	int i;

	if (x < 800 && y < 800 && x > 0 && y > 0)
	{
		i = (x * w->x / 8) + (y * w->size_line);
		w->img_data[i] = color * 10;
		w->img_data[++i] = color;
		w->img_data[++i] = color * 30;
		w->img_data[++i] = 0;
	}
}

void	draw(int x, int y, t_win *w)
{
	t_mdb	mdb;

	mdb.i = 0;
	mdb.max = 1000;
	while (mdb.i++ < x)
	{
		mdb.j = 0;
		while(mdb.j++ < y)
		{
			mdb.a = map(mdb.i, 0, x, -2, 2);
			mdb.b = map(mdb.j, 0, y, -2, 2);
			mdb.aval = mdb.a;
			mdb.bval = mdb.b;
			mdb.k = 0;
			while (mdb.k < mdb.max)
			{
				mdb.ab = mdb.a * mdb.a - mdb.b * mdb.b;
				mdb.bb = 2 * mdb.a * mdb.b;
				mdb.a = mdb.ab + mdb.aval;
				mdb.b = mdb.bb + mdb.bval;
				if (mdb.a * mdb.a + mdb.b * mdb.b > 4)
					break;
				mdb.k++;
			}
			mdb.color = mdb.k;
			if (mdb.k == mdb.max)
				mdb.color = 0;
			putimagein(mdb.i, mdb.j, mdb.color, w);
		}
	}
}

float	map(float n, float start1, float end1, float start2, float end2)
{
	return (((float)(n - start1) / (float)(end1 - start1)) * (end2 - start2) + start2);
}