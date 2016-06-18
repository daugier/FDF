/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:54:21 by daugier           #+#    #+#             */
/*   Updated: 2016/06/19 01:56:55 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_func(int keycode, t_struct *data)
{
	ft_new_screen(data);
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 126 || keycode == 125)
		H_PIC += keycode == 126 ? 10 : -10;
	if (keycode == 123 || keycode == 124)
		W_PIC += keycode == 124 ? 10: -10;
	if (keycode == 69 || keycode == 78)
		TOP += keycode == 69 ? 1 : -1;
	if (keycode == 116 || keycode == 121)
		ZOOM += keycode == 116 ? 1 : -1;
	if (keycode == 8)
		(CT1 += CT1 > 1 ? 0.1 : 0) && (CT2 += CT2 < 1 ? 0.1 : 0);
	if (keycode == 9)
		(CT1 += CT1 > 0.5 ? 0.1 : 0) && (CT2 += CT2 > 0.5 ? 0.1 : 0);
	if (keycode == 36)
		ft_init_pos(data);
	return (0);
}

int		ft_check_good_file(int ac, char **av)
{
	int fd;

	if (ac == 3 || ac > 4 || ac == 1)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
		exit(EXIT_FAILURE);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("No file ");
		ft_putstr(av[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int		main(int ac, char **av)
{
	t_struct		*data;
	int			fd;
	
	fd = ft_check_good_file(ac, av);
	data = ft_init_struct(ac, fd, av);
	ft_fdf(data);
	PUT_IMG = mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	mlx_key_hook(WIN, key_func, data);
	mlx_loop(MLX);
	return (0);
}
