/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:50:45 by daugier           #+#    #+#             */
/*   Updated: 2016/10/22 21:08:40 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_init_pos(t_struct *data)
{
	ZOOM = 15;
	TOP = 1;
	A = 1.5;
	H_PIC = 0;
	W_PIC = 0;
	CT1 = 1;
	CT2 = 1;
	COLORE = 0;
}

static void		check_file1(t_struct *data)
{
	int	x;

	x = -1;
	while (BUFFER[++x])
	{
		if (ft_isdigit(BUFFER[x]))
			return ;
	}
	ft_putstr("Wrong Map : Please enter a valid Map\n");
	exit(EXIT_SUCCESS);
}

static void		check_file2(t_struct *data)
{
	int	x;
	int	y;

	x = -1;
	while (BUFF[++x])
	{
		y = -1;
		while (BUFF[x][++y])
		{
			if (!ft_ishexa(BUFF[x][y]) && !ft_iswhite(BUFF[x][y]) &&
					BUFF[x][y] != '-' && BUFF[x][y] != ',')
			{
				ft_putstr("Wrong Map : Please enter a valid Map\n");
				exit(EXIT_SUCCESS);
			}
		}
		if (ft_lenchar(BUFF[x], ' ') != Y_MAX)
		{
			ft_putstr("Wrong Map : Please enter a valid Map\n");
			exit(EXIT_SUCCESS);
		}
	}
}

static void		stock_map(char *av, t_struct *data)
{
	int		x;

	x = -1;
	if (!(BUFFER = get_file(av)))
		exit(EXIT_SUCCESS);
	X_MAX = ft_lenchar(BUFFER, '\n');
	check_file1(data);
	if (!(BUFF = ft_strsplit(BUFFER, '\n')))
		exit(EXIT_FAILURE);
	Y_MAX = ft_lenchar(BUFF[x + 1], ' ');
	check_file2(data);
	if (!(MAP = (char***)ft_memalloc(sizeof(char**) * X_MAX + 1)))
		exit(EXIT_FAILURE);
	while (BUFF[++x])
		if (!(MAP[x] = ft_strsplit(BUFF[x], ' ')))
			exit(EXIT_FAILURE);
	MAP[x] = NULL;
}

t_struct		*ft_init_struct(char *av)
{
	t_struct	*data;

	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		exit(EXIT_FAILURE);
	stock_map(av, data);
	ft_init_pos(data);
	WIDTH += (X_MAX * 100 < 1800) ? X_MAX * 100 : 1800;
	HEIGHT += (Y_MAX * 100 < 1100) ? X_MAX * 100 : 1100;
	SIZE_LINE = WIDTH * (BPP / 8);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, av);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
	return (data);
}
