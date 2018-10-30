/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:59:53 by gzagura           #+#    #+#             */
/*   Updated: 2018/09/18 17:31:58 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 800
# define WIDTH  800
# define MAX_ITE 50

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <pthread.h>

typedef	struct			s_num
{
	double				nre;
	double				nim;
	double				ore;
	double				oim;
}						t_num;

typedef struct			s_fra
{
	int					y_st;
	int					y_end;
	int					iter;
	double				cxmin;
	double				cymin;
	double				cxmax;
	double				cymax;
	double				pr;
	double				pi;
	int					deep;
	int					i;
	void				*img;
	void				*wind;
	void				*mlx;
	char				*addr;
	char				name;
	char				*str;
	double				x_pr;
	double				y_pi;
	double				mousere;
	double				mouseim;
	int					move_flag;
	int					cor_x;
	int					cor_y;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	struct s_fra		*next;
	t_num				val;
}						t_fra;

void					ft_print_usage();
void					ft_init(t_fra *head, int tmp);
void					mandel(t_fra *head);
void					point_math(t_fra *head, t_num val, int x, int y);
void					multi_thread(t_fra *head);
void					math(t_fra *e, int x, int y);
void					*math_multi(void *e);
void					mandel(t_fra *head);
void					zoom_in(t_fra *head);
void					zoom_out(t_fra *head);
void					wrip(t_fra *fract,
							int count_pxl, double color, int bla);
void					applyzoom(t_fra *e, double zoomfactor);
void					calculs_dots(t_fra *fract, int x, int y, int flag);
int						le_hook(int key, t_fra *head);
int						ft_valid(int val, char **str);
int						ft_esc(t_fra *head);
int						pixels(int x, int y);
int						le_hook(int key, t_fra *head);
int						le_mouse_hook(int key, int x, int y, t_fra *head);
int						le_mouse_move(int x, int y, t_fra *head);
double					map(double x, double in_max,
							double out_min, double out_max);
double					interpolate(double start,
							double end, double interpolation);
#endif
