l/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 18:47:58 by gzagura           #+#    #+#             */
/*   Updated: 2018/09/18 18:14:21 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			multi_thread(t_fra *head)
{
	int			i;
	t_fra		tab[8];
	pthread_t	t[8];

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&tab[i], (void*)head, sizeof(t_fra));
		tab[i].y_st = 100 * i - 1;
		tab[i].y_end = 100 + 100 * i;
		i++;
	}
	i = 0;
	while (++i <= 8)
		pthread_create(&t[i - 1], NULL, math_multi, &tab[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
}

void			*math_multi(void *e)
{
	t_fra *head;

	head = e;
	math(head, -1, head->y_st);
	pthread_exit(0);
}

void			point_math(t_fra *head, t_num val, int x, int y)
{
	head->iter = -1;
	while (++head->iter < MAX_ITE)
	{
		val.ore = val.nre;
		val.oim = val.nim;
		if (head->name == 's')
		{
			val.nre = fabs(val.ore * val.ore - val.oim * val.oim + head->pr);
			val.nim = fabs(2 * val.ore * val.oim) + head->pi;
		}
		else
		{
			val.nre = val.ore * val.ore - val.oim * val.oim + head->pr;
			val.nim = 2 * val.ore * val.oim + head->pi;
		}
		if ((val.nre * val.nre + val.nim * val.nim) > 4)
			break ;
	}
	if (head->iter == MAX_ITE)
		wrip(head, pixels(x, y), (head->iter + head->deep) % 128, 0);
	else
		wrip(head, pixels(x, y), (head->iter + head->deep) % 128, 255);
}

void			math(t_fra *e, int x, int y)
{
	t_num	val;

	while (++y < e->y_end)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (e->name == 'm' || e->name == 's')
			{
				val.nre = 0;
				val.nim = 0;
				e->pr = ((e->cxmin + (x * ((e->cxmax - e->cxmin) / WIDTH))));
				e->pi = ((e->cymin + (y * ((e->cymax - e->cymin) / HEIGHT))));
			}
			else if (e->name == 'j')
			{
				val.nre = ((e->cxmin + (x * ((e->cxmax - e->cxmin) / WIDTH))));
				val.nim = ((e->cymin + (y * ((e->cymax - e->cymin) / HEIGHT))));
				e->pr = e->x_pr;
				e->pi = e->x_pr;
			}
			point_math(e, val, x, y);
		}
	}
}
