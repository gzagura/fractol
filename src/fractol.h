/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:59:53 by gzagura           #+#    #+#             */
/*   Updated: 2018/08/28 13:59:55 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#define	HEIGHT 1000
#define WIDTH  1000
#define	MAX_ITE 200



# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef	struct  	s_mand
{
	double			cim;
	double			cre;
}					t_mand;

typedef	struct  s_juli
{
	
}				t_juli;

typedef	struct  s_carp
{
	
}				t_carp;

typedef struct 			s_fra
{
	void				*img;
	void				*wind;
	void				*mlx;
	char				*addr;
	char				name;
	char				*str;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					w_width;
	int					w_height;
	double				x_pr;
	double				y_pi;
	double				pr;
	double				pi;
	double 				mouseRe;
	double 				mouseIm;
	double 				CxMin;
	double 				CyMin;
	double 				CxMax;
	double 				CyMax;
	int					flag;
	int					move_flag;
	int					iter;
	int					deep;
	int					cor_x;
	int					cor_y;
	int					name_flag;		
	struct s_fra		*next;
	t_mand				mand;
	t_juli				juli;
	t_carp				carp;		
}						t_fra;


void	mandel(t_fra *head);
void	write_pixel(t_fra *fract, int count_pxl, double color, int bla);
void applyZoom(t_fra *e, double zoomFactor);
void		calculs_dots(t_fra *fract, int x, int y, int flag);
void	mandel_math(t_fra *head, int x, int y);
void	carpet(t_fra *head);
int		ft_valid(int val, char **str);
int		ft_esc(t_fra *head);
int			calculs_pixel(int x, int y);
int		le_hook(int key, t_fra *head);
int		le_mouse_hook(int key, int x, int y, t_fra *head);
int 	le_mouse_move(int x, int y, t_fra *head);
#endif
