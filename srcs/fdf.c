/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:00:26 by daugier           #+#    #+#             */
/*   Updated: 2016/06/01 23:34:55 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_func(int keycode, t_struct *data)
{
	(void)data;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
/*	if (keycode == 123)
		ft_rotation_left();
	if (keycode == 124)
		ft_rotation_right();
	if (keycode == 125
		ft_rotation_bot();
	if (keycode == 126)
		ft_rotation_top();*/
	return (0);
}

void	ft_fdf(t_struct *data)
{
	X = 0;
	Y = 550;
	while (X < 500)
	{
		mlx_pixel_put(MLX, WIN, X, Y , 0X00FFFF);
		X++;
	}
	mlx_key_hook(WIN, key_func, data);
	mlx_loop(MLX);
	return ;
}
