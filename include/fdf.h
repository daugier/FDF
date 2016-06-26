/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:30:09 by daugier           #+#    #+#             */
/*   Updated: 2016/06/26 23:50:59 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "../libft/includes/libft.h"

# define BUFF data->buff
# define BUFFER data->buffer
# define COLORE data->colore
# define XINC data->xinc
# define YINC data->yinc
# define DX data->dx
# define DY data->dy
# define A data->a
# define Z data->z
# define X data->x
# define X1 data->x1
# define X2 data->x2
# define Y data->y
# define Y1 data->y1
# define Y2 data->y2
# define CT1 data->ct1
# define CT2 data->ct2
# define TOP data->top
# define ZOOM data->zoom
# define H_PIC data->height_picture
# define W_PIC data->width_picture
# define MLX data->mlx
# define WIN data->win
# define IMG data->img
# define BPP data->bit_per_pixel
# define Y_MAX data->y_max
# define X_MAX data->x_max
# define COLOR data->color_value
# define PUT_IMG data->mlx_put_img
# define ENDIAN data->endian
# define SIZE_LINE data->size_line
# define DATA data->data
# define HEIGHT data->height
# define WIDTH data->width
# define MAP data->map

typedef struct	s_struct
{
	int					xinc;
	int					yinc;
	float				a;
	int					x;
	int					x1;
	int					x2;
	int					y;
	int					dx;
	int					dy;
	int					z;
	int					y1;
	int					y2;
	void				*mlx;
	void				*win;
	void				*img;
	char				*buffer;
	char				**buff;
	char				***map;
	char				*data;
	int					size_line;
	int					colore;
	unsigned long int	color_value;
	int					mlx_put_img;
	int					x_max;
	int					y_max;
	int					endian;
	int					bit_per_pixel;
	int					width;
	int					height;
	float				ct1;
	float				ct2;
	int					zoom;
	int					height_picture;
	int					width_picture;
	int					top;
}				t_struct;

void				write_screen(t_struct *data);
void				write_data_pixel(t_struct *data);
int					define_x(t_struct *data, int x, int y);
int					define_y(t_struct *data, int x, int y);
void				draw_line_x(t_struct *data);
void				draw_line_y(t_struct *data);
void				ft_init_pos(t_struct *data);
t_struct			*ft_init_struct(char *av);
int					ft_fdf(t_struct *data);
void				ft_new_screen(t_struct *data);
void				get_color(t_struct *data, char *str);

#endif
