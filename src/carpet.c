/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:31:36 by gzagura           #+#    #+#             */
/*   Updated: 2018/09/13 18:31:39 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int isSierpinskiCarpetPixelFilled(int x, int y)
{
    while (x > 0 || y > 0) // when either of these reaches zero the pixel is determined to be on the edge 
                               // at that square level and must be filled
    {
        if (x % 3 == 1 && y % 3 == 1) //checks if the pixel is in the center for the current square level
            return 0;
        x /= 3; //x and y are decremented to check the next larger square level
        y /= 3;
    }
    return 1; // if all possible square levels are checked and the pixel is not determined 
                   // to be open it must be filled
}

void	put_pixel(t_fra *head, int x, int y, int color)
{
	int count_pxl;

	count_pxl = calculs_pixel(x, y);
	write_pixel(head, count_pxl, color, color);
}

void	carpet(t_fra *head)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (isSierpinskiCarpetPixelFilled(x, y) == 0)
			{
				put_pixel(head, x, y, 0);
			}
			else
				put_pixel(head, x, y, 255);
		}
	}
}