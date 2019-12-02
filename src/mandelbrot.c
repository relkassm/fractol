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
	w->max = 100;
	w->xy = 800 + w->zm;
	while (w->i++ < w->xy)
	{
		w->j = 0;
		while (w->j++ < w->xy)
		{
			w->a = map(w->i, w->x0, w->xy + w->x0);
			w->b = map(w->j, w->y0, w->xy + w->y0);
			w->aval = w->a;
			w->bval = w->b;
			w->k = 0;
			process(w);
			putimagein(w->i, w->j, w->color, w);
		}
	}
}

void	process(t_win *w)
{
	while (w->k < w->max)
	{
		w->ab = w->a * w->a - w->b * w->b;
		w->bb = 2 * w->a * w->b;
		w->a = w->ab + w->aval;
		w->b = w->bb + w->bval;
		if (w->a * w->a + w->b * w->b > 4)
			break ;
		w->k++;
	}
	w->color = w->k;
	if (w->k == w->max)
		w->color = 0;
}
