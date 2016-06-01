/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:00:26 by daugier           #+#    #+#             */
/*   Updated: 2016/06/01 12:12:19 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_func(int keycode, t_struct *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
/*	if (keycode == 123)
		ft_rotation_left();
	if (keycode == 124)
		ft_rotation_right();
	if (keycode == 125)
		ft_rotation_bot();
	if (keycode == 126)
		ft_rotation_top();*/
	return (0);
}

t_struct	*ft_init_struct(int ac, char **av, char *buffer)
{
	t_struct	*param;

	if (!(param = (t_struct *)malloc(sizeof(t_struct))))
		exit(EXIT_FAILURE);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 600, 600, "COOOL");
	if (ac == 4)
	{
		E1 = ft_atoi(av[2]);
		E2 = ft_atoi(av[3]);
	}

	return (param);
}

void	ft_fdf(t_struct *param)
{
	while (X < 500)
	{
		mlx_pixel_put(MLX, WIN, X, Y , 0X00FFFF);
		X++;
	}
	mlx_key_hook(WIN, key_func, param);
	mlx_loop(MLX);
	return ;
}

int		ft_check_good_file(int ac, char **av, t_struct *param)
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
	t_struct		*param;
	char		*buffer;
	int			fd;
	
	fd = ft_check_good_file(ac, av, param);
	if (!(buffer = ft_getmap(fd)))
		exit(EXIT_FAILURE);
	param = ft_init_struct(ac, av, buffer);
	ft_fdf(param);
	return (0);
}
