/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:54:21 by daugier           #+#    #+#             */
/*   Updated: 2017/01/31 16:37:24 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		free_all(t_struct *data)
{
	int	x;

	x = -1;
	while (MAP[++x])
		ft_free_tab(MAP[x]);
	free(MAP);
	x = -1;
	while (BUFF[++x])
		free(BUFF[x]);
	free(BUFF);
	free(BUFFER);
	free(data);
	data = NULL;
}

static void		change_color(int keycode, t_struct *data)
{
	if (keycode > 17 && keycode < 26)
		COLORE = 1;
	if (keycode == 19)
		COLORE = 0;
	if (keycode == 20)
		COLOR = 0xFF0000;
	if (keycode == 21)
		COLOR = 0x00FF00;
	if (keycode == 22)
		COLOR = 0x0000FF;
	if (keycode == 23)
		COLOR = 0xFFFF00;
	if (keycode == 26)
		COLOR = 0x00FFFF;
	if (keycode == 28)
		COLOR = 0xFF00FF;
	if (keycode == 25)
	{
		COLOR = 0xCcc00C;
		COLORE = 2;
	}
}

static void		moove_map(int keycode, t_struct *data)
{
	if (keycode == 126 || keycode == 125)
		H_PIC += keycode == 126 ? -30 : 30;
	if (keycode == 123 || keycode == 124)
		W_PIC += keycode == 124 ? 30 : -30;
	if (keycode == 69 || keycode == 78)
		TOP += keycode == 69 ? 1 : -1;
	if (keycode == 67 || keycode == 75)
	{
		if (A - 0.4 > 0.4 && keycode == 75)
			A += -0.4;
		else if (keycode == 67)
			A += 0.4;
	}
	if (keycode == 18)
		COLORE = 3;
}

static int		key_func(int keycode, t_struct *data)
{
	change_color(keycode, data);
	moove_map(keycode, data);
	if (keycode == 53)
	{
		free_all(data);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 116 || keycode == 121)
	{
		if (ZOOM - 2 > 0 && keycode == 121)
			ZOOM -= 2;
		else if (keycode == 116)
			ZOOM += 2;
	}
	if (keycode == 36)
		ft_init_pos(data);
	return (1);
}

int				main(int ac, char **av)
{
	t_struct		*data;

	if (ac == 3 || ac > 4 || ac == 1)
	{
		ft_putstr("Usage : ./fdf <filename>\n");
		exit(EXIT_FAILURE);
	}
	data = ft_init_struct(av[1]);
	ft_fdf(data);
	mlx_loop_hook(MLX, ft_fdf, data);
	mlx_key_hook(WIN, key_func, data);
	mlx_loop(MLX);
	free_all(data);
	return (0);
}
