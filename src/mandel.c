/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:37:47 by gzagura           #+#    #+#             */
/*   Updated: 2018/08/29 16:37:49 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel(t_fra *head)
{
	ft_bzero(head->addr, ft_strlen(head->addr));
	mandel_math(head,  -1, -1);
	mlx_put_image_to_window(head->mlx, head->wind, head->img, 0 , 0);
	mlx_string_put(head->mlx, head->wind, 10, 0, 255, head->str);
}

int			calculs_pixel(int x, int y)
{
	int		count_pix;

	count_pix = 0;
	count_pix = (x * 4) + ((WIDTH * 4) * y);
	return (count_pix);
}


void	write_pixel(t_fra *fract, int count_pxl, double color, int bla)
{
	if (bla == 0)
	{
		fract->addr[count_pxl] = 0;
		fract->addr[count_pxl + 1] = 0;
		fract->addr[count_pxl + 2] = 0;
	}
	else
	{
		fract->addr[count_pxl] = (int)color;
		fract->addr[count_pxl + 1] = color - 133 / 3;
		fract->addr[count_pxl + 2] = color * 66;
	}
}

void	put_color(t_fra *head, int x, int y, int color)
{
	int count_pxl;

	count_pxl = calculs_pixel(x, y);
	write_pixel(head, count_pxl, (head->iter + head->deep) % 128, color);
}

void	mandel_math(t_fra *head, int x, int y)
{
    long double CxMin= head->CxMin;
    long double CxMax= head->CxMax;
    long double CyMin= head->CyMin;
    long double CyMax= head->CyMax;
  	double newRe, newIm, oldRe, oldIm;
    double PixelWidth= ((CxMax-CxMin)/WIDTH);
    double PixelHeight= ((CyMax-CyMin)/HEIGHT);

	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (head->name == 'm')
			{
				newRe = 0;
      			newIm = 0;
      			oldRe = 0;
      			oldIm = 0;
      			head->pr = ((CxMin + (x*PixelWidth)));
      			head->pi = ((CyMin + (y*PixelHeight)));
      		}
      		if (head->name == 'j')
			{
				
				newRe = ((CxMin + (x*PixelWidth)));
      			newIm = ((CyMin + (y*PixelHeight)));
      			head->pr = head->x_pr;
      			head->pi = head->y_pi;;
      		}
			head->iter = -1;
			while (++head->iter < MAX_ITE)
			{
				oldRe = newRe;
        		oldIm = newIm;
        		newRe = oldRe * oldRe - oldIm * oldIm + head->pr;
        		newIm = 2 * oldRe * oldIm + head->pi;
        		if((newRe * newRe + newIm * newIm) > 4) break;
			}
			if (head->iter == MAX_ITE)
			{
				put_color(head, x, y, 0);
			}
			else
				put_color(head, x, y, 255);
			
		}
	}
}








