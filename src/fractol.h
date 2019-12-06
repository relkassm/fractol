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
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_win
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*img_data;
	int					map;
	int					x;
	int					y;
	int					size_line;
	int					end;
	int					i;
	int					j;
	int					k;
	int					max;
	int					color;
	int					height;
	int					iter;
	int					julia_pause;
	int					red;
	int					green;
	int					blue;
	long double			zm;
	long double			a;
	long double			b;
	long double			a_value;
	long double			b_value;
	long double			real;
	long double			imgn;
	long double			start_x;
	long double			start_y;
	long double			end_x;
	long double			end_y;
	long double			s2;
	long double			e2;
	long double			x0;
	long double			y0;
	long double			julx;
	long double			july;
	long double			mouse_x;
	long double			mouse_y;
}					t_win;

void				init(int n);
void				putimagein(int x, int y, int color, t_win *w);
void				mlx_start(int n, t_win w);

void				mandelbrot(t_win *w);
void				process_mandelbrot(t_win *w);

void				julia(t_win *w);
void				process_julia(t_win *w);

void				burningship(t_win *w);
void				process_burningship(t_win *w);

int					mouse_press(int b, int x, int y, t_win *w);
int					mouse_move(int x, int y, t_win *w);
void				keypart(int key, t_win *w, int *a);
int					keypress(int key, t_win *w);
void				fract(t_win *w);

long double			map(long double start, long double end,\
					long double interpolation);
void				zoom(t_win *w, long double m_x, long double m_y,\
					long double zoom);

void				ft_putchar(char x);
void				ft_putendl(char const *s);
int					ft_strcmp(const char *s, const char *ss);
long double			ft_abs(long double n);

#endif
