/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:59:07 by gzagura           #+#    #+#             */
/*   Updated: 2018/09/18 17:52:22 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_esc(t_fra *head)
{
	mlx_destroy_window(head->mlx, head->wind);
	write(1, "Bye-Bye\n", 8);
	exit(1);
	return (0);
}

void	ft_print_usage(void)
{
	write(1, "usage : fractol [fractals]\nfractals:\n--> M = Mandelbrot\n", 56);
	write(1, "--> J = Julia\n--> S = Ship\nExample: ./fractol M\n", 48);
	exit(1);
}

int		ft_valid(int val, char **str)
{
	if (val == 2)
	{
		if (ft_strcmp(str[1], "M") == 0)
		{
			ft_putstr("Mandel v dele\n");
			return (1);
		}
		else if (ft_strcmp(str[1], "J") == 0)
		{
			ft_putstr("Juli v dele\n");
			return (2);
		}
		else if (ft_strcmp(str[1], "S") == 0)
		{
			ft_putstr("Ship v dele\n");
			return (3);
		}
	}
	ft_print_usage();
	return (0);
}

void	ft_init(t_fra *head, int tmp)
{
	if (tmp == 1)
	{
		head->name = 'm';
		head->cxmin = -2.5;
		head->cxmax = 1.5;
		head->cymin = -2.0;
		head->cymax = 2.0;
	}
	if (tmp == 2)
	{
		head->name = 'j';
		head->cxmin = -2.5;
		head->cxmax = 2.3;
		head->cymin = -2.3;
		head->cymax = 2.5;
	}
	if (tmp == 3)
	{
		head->name = 's';
		head->cxmin = -2.5;
		head->cxmax = 1.0;
		head->cymin = -1;
		head->cymax = 1;
	}
	mandel(head);
}

int		main(int argc, char **argv)
{
	t_fra	*head;
	int		tmp;

	head = malloc(sizeof(t_fra));
	if ((tmp = ft_valid(argc, argv)) > 0)
	{
		head->mlx = mlx_init();
		head->wind = mlx_new_window(head->mlx, WIDTH, HEIGHT, "fractol");
		head->img = mlx_new_image(head->mlx, WIDTH, HEIGHT);
		head->deep = 1;
		head->move_flag = 1;
		head->addr = mlx_get_data_addr(head->img,
			&(head->bits_per_pixel), &(head->size_line), &(head->endian));
		ft_init(head, tmp);
		mlx_hook(head->wind, 17, 1L << 17, ft_esc, head);
		mlx_hook(head->wind, 2, 0, le_hook, head);
		mlx_mouse_hook(head->wind, le_mouse_hook, head);
		mlx_hook(head->wind, 6, (1L << 6), le_mouse_move, head);
		mlx_loop(head->mlx);
	}
	return (0);
}
