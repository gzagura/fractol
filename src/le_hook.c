/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:47:41 by gzagura           #+#    #+#             */
/*   Updated: 2018/09/03 14:47:45 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		le_hook(int key, t_fra *head)
{
	if (key == 53)
		ft_esc(head);
	if (key == 2)
	{
		head->deep++;
		mandel(head);
	}
	if (key == 46)
		head->move_flag = head->move_flag > 0 ? 0 : 1;
	return (0);
}

void	zoom_in(t_fra *head)
{
		head->deep--;
		applyZoom(head, 0.9);
		mandel(head);
	
}

void	zoom_out(t_fra *head)
{
		head->deep++;
		applyZoom(head, 1.1);
		mandel(head);
}


double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

double map(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int		le_mouse_hook(int key, int x, int y, t_fra *head)
{
	head->cor_x = x;
	head->cor_y = y;
	head->x_pr = map(x, 0, WIDTH, -1, 1);
	head->y_pi = map(y, 0, HEIGHT, -1, 1);
	if (key == 5)
		zoom_in(head);
	if (key == 4)
		zoom_out(head);
	return (0);
}



void applyZoom(t_fra *e, double zoomFactor)
{

	e->mouseRe = (double)e->cor_x / (WIDTH / (e->CxMax - e->CxMin)) + e->CxMin;
	e->mouseIm = (double)e->cor_y / (HEIGHT / (e->CyMax - e->CyMin)) + e->CyMin;
     double interpolation = 1.0 / zoomFactor;
     e->CxMin = interpolate(e->mouseRe, e->CxMin, interpolation);
     e->CyMin = interpolate(e->mouseIm, e->CyMin, interpolation);
     e->CxMax = interpolate(e->mouseRe, e->CxMax, interpolation);
     e->CyMax = interpolate(e->mouseIm, e->CyMax, interpolation);
}

int 	le_mouse_move(int x, int y, t_fra *head)
{
	
	int tmp1;
	int tmp2;
	
	tmp2 = 0;	
	tmp1 = 0;
	head->str = NULL;
	if (x != tmp1 || y != tmp2)
	{
		tmp1 = x;
		tmp2 = y;
		head->str = ft_strdup("x: ");
		head->str = ft_strjoin(head->str, ft_itoa(x));
		head->str = ft_strjoin(head->str, " y: ");
		head->str = ft_strjoin(head->str, ft_itoa(y));
	}
	if (head->name == 'j' && head->move_flag == 1)
	{
		head->x_pr = map(x, 0, WIDTH, -1, 1);
		head->y_pi = map(y, 0, HEIGHT, -1, 1);
		mandel(head);
	}
	mlx_clear_window(head->mlx, head->wind);
	mlx_put_image_to_window(head->mlx, head->wind, head->img, 0 , 0);
	mlx_string_put(head->mlx, head->wind, 10, 0, 255, head->str);
	return (0);
}