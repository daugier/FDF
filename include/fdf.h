/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:30:09 by daugier           #+#    #+#             */
/*   Updated: 2016/06/19 01:56:49 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H_
# define FDF_H_

# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "../libft/include/libft.h"

# define HEXA "0123456789ABCDEF"
# define DECI "0123456789"
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
# define X data->x
# define Y data->y
# define Z data->z
# define ALTITUDE data->altitude
# define Y_TAIL data->y_tail
# define X_TAIL data->x_tail
# define COLOR data->color_value
# define PUT_IMG data->mlx_put_img
# define DATA_ADD data->data_add
# define ENDIAN data->endian
# define SIZE_LINE data->size_line
# define DATA data->data
# define HEIGHT data->height
# define WIDTH data->width
# define E1 data->e1
# define E2 data->e2
# define MAP data->map

typedef struct	s_struct
{
	void	*mlx;
	void	*win;
	void	*img;
	char	***map;
	char	*data_add;
	int		size_line;
	unsigned int	color_value;
	int		mlx_put_img;
	int		ct1;
	int		ct2;
	int		x_tail;
	int		altitude;
	int		y_tail;
	int		endian;
	int		bit_per_pixel;
	int		width;
	int		zoom;
	int		height_picture;
	int		width_picture;
	int		top;
	int		height;
	int		e1;
	int		e2;
	int		x;
	int		y;
	int		z;
}				t_struct;

void			ft_stock_map(int fd, t_struct *data);
t_struct		*ft_init_struct(int ac, int fd, char **av);
void			ft_fdf(t_struct *data);
void			ft_init_pos(t_struct *data);
void			ft_new_screen(t_struct *data);

#endif
