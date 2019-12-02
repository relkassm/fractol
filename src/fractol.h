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
	int		x;
	int		y;
	int		x0;
	int		y0;
	int		size_line;
	int		end;
	int		i;
	int		j;
	int		k;
	int		max;
	int		pix;
	int		color;
	int		xy;
	int		zm;
	float	a;
	float	b;
	float	aval;
	float	bval;
	float	ab;
	float	bb;
}				t_win;

typedef struct	s_map
{
	float	start1;
	float	start2;
	float	end1;
	float	end2;
	float	n;
}				t_map;

void			init(int n);
void			putimagein(int x, int y, int color, t_win *w);
float			map(float n, float start, float end);

void			mandelbrot(t_win *w);
void			process(t_win *w);

int				mouse_press(int b, int x, int y, t_win *w);
int				mouse_move(int x, int y, t_win *w);
void			keypart(int key, t_win *w, int *a);
int				keypress(int key, t_win *w);

#endif
