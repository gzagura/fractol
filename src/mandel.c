/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:37:47 by gzagura           #+#    #+#             */
/*   Updated: 2018/09/18 17:16:22 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel(t_fra *head)
{
	ft_bzero(head->addr, ft_strlen(head->addr));
	multi_thread(head);
	mlx_put_image_to_window(head->mlx, head->wind, head->img, 0, 0);
}

int		pixels(int x, int y)
{
	int		count_pix;

	count_pix = 0;
	count_pix = (x * 4) + ((WIDTH * 4) * y);
	return (count_pix);
}

void	wrip(t_fra *fract, int count_pxl, double color, int bla)
{
	if (bla == 0)
	{
		fract->addr[count_pxl] = 0;
		fract->addr[count_pxl + 1] = 0;
		fract->addr[count_pxl + 2] = 0;
	}
	else
	{
		fract->addr[count_pxl] = color * 2;
		fract->addr[count_pxl + 1] = color * 4;
		fract->addr[count_pxl + 2] = color * 6;
	}
}
