/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:54:21 by daugier           #+#    #+#             */
/*   Updated: 2016/06/20 18:35:34 by daugier          ###   ########.fr       */
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
		W_PIC += keycode == 124 ? 10 : -10;
	if (keycode == 69 || keycode == 78)
		TOP += keycode == 69 ? 1 : -1;
	if (keycode == 116 || keycode == 121)
		ZOOM += keycode == 116 ? 2 : -2;
	if (keycode == 8)
		(CT1 += CT1 > 1 ? 0.1 : 0) && (CT2 += CT2 < 1 ? 0.1 : 0);
	if (keycode == 9)
		(CT1 += CT1 > 0.5 ? 0.1 : 0) && (CT2 += CT2 > 0.5 ? 0.1 : 0);
	if (keycode == 36)
		ft_init_pos(data);
	return (1);
}

void	ft_check_good_file(int ac)
{
	if (ac == 3 || ac > 4 || ac == 1)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
		exit(EXIT_FAILURE);
	}
}

int		main(int ac, char **av)
{
	t_struct		*data;
	t_point			*p;

	if (!(p = (t_point *)malloc(sizeof(t_point))))
		exit(EXIT_FAILURE);
	ft_check_good_file(ac);
	data = ft_init_struct(av[1]);
	data = ft_init_struct(av[1]);
	//mlx_expose_hook(MLX,ft_fdf, data);
	mlx_key_hook(WIN, key_func, data);
	mlx_loop_hook(MLX, ft_fdf, data);
	mlx_loop(MLX);
	return (0);
}
