/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:57:47 by relkassm          #+#    #+#             */
/*   Updated: 2019/12/02 14:58:20 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_win *w)
{
	w->i = 0;
	w->max = w->iter;
	w->height = 800;
	w->map = 2;
	while (w->i++ < w->height)
	{
		w->j = 0;
		while (w->j++ < w->height)
		{
			w->a = ((w->i - w->start_x /*- w->x0*/) / (w->end_x - w->start_x)) * ((w->e2) - (w->s2)) + (w->s2);
			w->b = ((w->j - w->start_y /*- w->y0*/) / (w->end_y - w->start_y)) * ((w->e2) - (w->s2)) + (w->s2);
			w->aval = w->a;
			w->bval = w->b;
			w->k = 0;
			process_mandelbrot(w);
			putimagein(w->i, w->j, w->color, w);
		}
	}
}

void	process_mandelbrot(t_win *w)
{
	while (w->k < w->max)
	{
		w->real = w->a * w->a - w->b * w->b;
		w->imgn = 2 * w->a * w->b;
		w->a = w->real + w->aval;
		w->b = w->imgn + w->bval;
		if (w->a * w->a + w->b * w->b > 4)
			break ;
		w->k++;
	}
	w->color = w->k;
	if (w->k == w->max)
		w->color = 0;
}
