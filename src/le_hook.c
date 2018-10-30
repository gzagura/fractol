/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:47:41 by gzagura           #+#    #+#             */
/*   Updated: 2018/09/18 17:43:20 by gzagura          ###   ########.fr       */
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
	if (key == 69)
		zoom_in(head);
	if (key == 78)
		zoom_out(head);
	return (0);
}

double	map(double x, double in_max, double out_min, double out_max)
{
	return (x - 0) * (out_max - out_min) / (in_max - 0) + out_min;
}

int		le_mouse_hook(int key, int x, int y, t_fra *head)
{
	(void)x;
	(void)y;
	if (key == 4)
		zoom_in(head);
	if (key == 5)
		zoom_out(head);
	return (0);
}

int		le_mouse_move(int x, int y, t_fra *head)
{
	head->cor_x = x;
	head->cor_y = y;
	head->str = NULL;
	if (head->move_flag == 1 && head->name == 'j')
	{
		head->x_pr = map(x, WIDTH, -1, 1);
		head->y_pi = map(y, HEIGHT, -1, 1);
		mandel(head);
	}
	mlx_clear_window(head->mlx, head->wind);
	mlx_put_image_to_window(head->mlx, head->wind, head->img, 0, 0);
	mlx_string_put(head->mlx, head->wind, 10, 10,
		255, "Stop moving Julia press M");
	mlx_string_put(head->mlx, head->wind, 10, 30,
		255, "To zoom use mouse's wheel");
	mlx_string_put(head->mlx, head->wind, 10, 50,
		255, "Sincerly yours gZagura");
	return (0);
}
