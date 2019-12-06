/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:21:49 by relkassm          #+#    #+#             */
/*   Updated: 2019/12/02 15:21:51 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_win *w)
{
	w->i = 0;
	w->map = 1;
	while (w->i++ < w->height)
	{
		w->j = 0;
		while (w->j++ < w->height)
		{
			w->a = ((w->i - w->start_x - w->x0) / (w->end_x - w->start_x))\
			* ((w->e2) - (w->s2)) + (w->s2);
			w->b = ((w->j - w->start_y - w->y0) / (w->end_y - w->start_y))\
			* ((w->e2) - (w->s2)) + (w->s2);
			w->k = 0;
			process_julia(w);
			putimagein(w->i, w->j, w->color, w);
		}
	}
}

void	process_julia(t_win *w)
{
	while (w->k < w->iter)
	{
		w->real = w->a * w->a - w->b * w->b;
		w->imgn = 2 * w->a * w->b;
		w->a = w->real + w->julx;
		w->b = w->imgn + w->july;
		if (w->a * w->a + w->b * w->b > 4)
			break ;
		w->k++;
	}
	w->color = w->k;
	if (w->k == w->iter)
		w->color = 0;
}
