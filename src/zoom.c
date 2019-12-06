/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkassm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:52:14 by relkassm          #+#    #+#             */
/*   Updated: 2019/12/06 19:52:16 by relkassm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	map(long double start, long double end, long double zoom)
{
	long double value;

	value = start + ((end - start) * zoom);
	return (value);
}

void		zoom(t_win *w, long double m_x, long double m_y, long double zoom)
{
	w->mouse_x = w->start_x + ((long double)m_x\
	* (w->end_x - w->start_x) / 800);
	w->mouse_y = w->start_y + ((long double)m_y\
	* (w->end_y - w->start_y) / 800);
	w->start_x = map(m_x, w->start_x, zoom);
	w->end_x = map(m_x, w->end_x, zoom);
	w->start_y = map(m_y, w->start_y, zoom);
	w->end_y = map(m_y, w->end_y, zoom);
}
