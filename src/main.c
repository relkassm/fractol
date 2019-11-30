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
		{
			init(1);
		}
		else if (ft_strcmp(av[1], "mandelbrot") == 0 || ft_strcmp(av[1], "2") == 0)
		{
			init(2);
		}
		else if (ft_strcmp(av[1], "yikes") == 0 || ft_strcmp(av[1], "3") == 0)
		{
			init(3);
		}
		else
		{
			ft_putendl("Plese chose one of the following types of fractals :\n 1 - Julia\n 2 - Mandelbrot\n 3 - Yikes");
		}
	}
	else
		ft_putendl("usage :  ./fracol [Fractal's Type]\n 1 - Julia\n 2 - Mandelbrot\n 3 - Yikes");
	return (0);
}

void	init(int n)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1600, 800, "Fracol");
	img_ptr = mlx_new_image(mlx_ptr, 1600, 800);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	if (n == 1)
		ft_putendl("Julia");
	else if (n == 2)
		ft_putendl("Mandelbrot");
	else if (n == 3)
		ft_putendl("Yikes");
}