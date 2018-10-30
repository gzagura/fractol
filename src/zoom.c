/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 22:35:38 by gzagura           #+#    #+#             */
/*   Updated: 2018/09/15 22:35:39 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_out(t_fra *head)
{
	head->deep--;
	applyzoom(head, 0.9);
	mandel(head);
}

void	zoom_in(t_fra *head)
{
	head->deep++;
	applyzoom(head, 1.1);
	mandel(head);
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applyzoom(t_fra *e, double zoomfactor)
{
	double interpolation;

	interpolation = 1.0 / zoomfactor;
	e->mousere = (double)e->cor_x / (WIDTH / (e->cxmax - e->cxmin)) + e->cxmin;
	e->mouseim = (double)e->cor_y / (HEIGHT / (e->cymax - e->cymin)) + e->cymin;
	e->cxmin = interpolate(e->mousere, e->cxmin, interpolation);
	e->cymin = interpolate(e->mouseim, e->cymin, interpolation);
	e->cxmax = interpolate(e->mousere, e->cxmax, interpolation);
	e->cymax = interpolate(e->mouseim, e->cymax, interpolation);
}
