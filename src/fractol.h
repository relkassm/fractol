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

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		map;
	int		x;
	int		y;
	int		size_line;
	int		end;
	int		i;
	int		j;
	int		k;
	int		max;
	int		pix;
	int		color;
	int		height;
	float	iter;
	float	zm;
	float	a;
	float	b;
	float	aval;
	float	bval;
	float	real;
	float	imgn;
	float	start_x;
	float	start_y;
	float	end_x;
	float	end_y;
	float	s2;
	float	e2;
	float	x0;
	float	y0;
	float	julx;
	float	july;
	float	mouse_x;
	float	mouse_y;
}				t_win;

void			init(int n);
void			putimagein(int x, int y, int color, t_win *w);
float			interpolate(float start, float end, float interpolation);
void			zoom(t_win* w, float mouse_x, float mouse_y, float zoomFactor);

void			mandelbrot(t_win *w);
void			process_mandelbrot(t_win *w);

void			julia(t_win *w);
void			process_julia(t_win *w);

void			burningship(t_win *w);
void			process_burningship(t_win *w);
float   		ft_abs(float n);

int				mouse_press(int b, int x, int y, t_win *w);
int				mouse_move(int x, int y, t_win *w);
void			keypart(int key, t_win *w, int *a);
int				keypress(int key, t_win *w);

#endif
