/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:50:45 by daugier           #+#    #+#             */
/*   Updated: 2016/06/20 18:38:57 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_point(t_point *p)
{
	X = 0;
	X1 = 0;
	X2 = 0;
	Y = 0;
	Y1 = 0;
	Y2 = 0;
}

void		ft_new_screen(t_struct *data)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
}

void		ft_init_pos(t_struct *data)
{
	ZOOM = 2;
	TOP = 1;
	H_PIC = 0;
	W_PIC = 0;
	CT1 = 1;
	CT2 = 1;
}

void		ft_stock_map(char *av, t_struct *data)
{
	char	*buffer;
	char	**buff;
	int		x;

	x = 0;
	if (get_file(av, &buffer) == -1)
	{
		ft_putstr("No file ");
		ft_putstr(av);
		ft_putstr("\n");
		exit(EXIT_FAILURE);
	}
	X_MAX = ft_lenchar(buffer, '\n');
	if (!(MAP = (char***)ft_memalloc(sizeof(char**) * X_MAX + 1)))
		exit(EXIT_FAILURE);
	if (!(buff = ft_strsplit(buffer, '\n')))
		exit(EXIT_FAILURE);
	Y_MAX = ft_lenchar(buff[x], ' ');
	while (buff[x])
	{
		if (!(MAP[x] = ft_strsplit(buff[x], ' ')))
			exit(EXIT_FAILURE);
		x++;
	}
	MAP[x] = NULL;
}

t_struct	*ft_init_struct(char *av)
{
	t_struct	*data;

	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		exit(EXIT_FAILURE);
	WIDTH = 1600;
	HEIGHT = 1600;
	BPP = 24;
	ENDIAN = 1;
	SIZE_LINE = WIDTH * (BPP / 8);
	ft_stock_map(av, data);
	WIDTH = 1200;
	HEIGHT = 800;
	ZOOM = 2;
	TOP = 1;
	H_PIC = 0;
	W_PIC = 0;
	CT1 = 1;
	CT2 = 1;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, av);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
	return (data);
}