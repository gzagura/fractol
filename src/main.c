/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:59:07 by gzagura           #+#    #+#             */
/*   Updated: 2018/08/28 13:59:08 by gzagura          ###   ########.fr       */
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

void	ft_print_usage()
{
	write(1, "usage : fractol [fractals]\nfractals:\n--> M = Mandelbrot\n", 56);
	write(1, "--> J = Julia\n--> C = Carpet\nExample: ./fractol M\n", 50);
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
			ft_putstr("Juli v dele");
			return (2);
		}
		else if (ft_strcmp(str[1], "C") == 0)
		{
			ft_putstr("KOver v dele");
			return (3);
		}
	}
	ft_print_usage();
	return (0);
}

int		main(int argc, char **argv)
{
	t_fra	*head;
	int 	tmp;

	head = malloc(sizeof(t_fra));
	if ((tmp = ft_valid(argc, argv)) > 0)
	{
		head->mlx = mlx_init();
		head->w_width = WIDTH;
		head->w_height = HEIGHT;
		head->wind = mlx_new_window(head->mlx, WIDTH, HEIGHT, "fractol");
		head->img = mlx_new_image(head->mlx, WIDTH, HEIGHT);
		head->deep = 1;
		head->cor_x = 0;
		head->cor_y = 0;
		head->CxMin=-2.5;
    	head->CxMax=1.5;
    	head->CyMin=-2.0;
    	head->CyMax=2.0;
    	head->move_flag = 1;
		head->addr = mlx_get_data_addr(head->img, &(head->bits_per_pixel), &(head->size_line), &(head->endian));
		if (tmp == 1)
		{
			head->name = 'm';
			mandel(head);
		}
		if (tmp == 2)
		{
			head->name = 'j';
			head->CxMin=-2.5;
	    	head->CxMax=2.3;
	    	head->CyMin=-2.3;
	    	head->CyMax=2.5;
			mandel(head);
			// ft_julia(head);
		}
		if (tmp == 3)
		{
			head->name = 'c';
			carpet(head);
		}
		mlx_hook(head->wind, 17, 1L << 17, ft_esc, head);
		mlx_hook(head->wind, 2, 0, le_hook, head);
		mlx_mouse_hook(head->wind, le_mouse_hook, head);
		mlx_hook(head->wind, 6, (1L << 6), le_mouse_move, head);
		mlx_loop(head->mlx);
	}
	return (0);
}
