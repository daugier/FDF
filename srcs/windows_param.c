/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 20:16:52 by daugier           #+#    #+#             */
/*   Updated: 2017/01/31 16:39:36 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		write_info_screen(t_struct *data)
{
	mlx_string_put(MLX, WIN, (WIDTH / 2) - 100, 5, 0x00bfff,
			"Touches disponibles");
	mlx_string_put(MLX, WIN, 20, 25, 0x00bfff, "Entrer   -> Reset");
	mlx_string_put(MLX, WIN, 20, 40, 0x00bfff, "+ ou -   -> Hauteur");
	mlx_string_put(MLX, WIN, 20, 55, 0x00bfff, "/ ou *   -> Angle");
	mlx_string_put(MLX, WIN, (WIDTH / 2) - 125, 25, 0x00bfff,
			"Fleche gauche -> Gauche");
	mlx_string_put(MLX, WIN, (WIDTH / 2) - 125, 40, 0x00bfff,
			"Fleche droite -> Droite");
	mlx_string_put(MLX, WIN, (WIDTH / 2) - 125, 55, 0x00bfff,
			"Fleche bas    -> Bas");
	mlx_string_put(MLX, WIN, (WIDTH / 2) - 125, 70, 0x00bfff,
			"Fleche haut   -> Haut");
	mlx_string_put(MLX, WIN, (WIDTH - 290), 25, 0x00bfff,
			"De 1 a 9      -> Couleur");
	mlx_string_put(MLX, WIN, (WIDTH - 290), 40, 0x00bfff,
			"Page up       -> Zoomer");
	mlx_string_put(MLX, WIN, (WIDTH - 290), 55, 0x00bfff,
			"Page down     -> Dezoomer");
}

void			write_screen(t_struct *data)
{
	write_info_screen(data);
}

void			ft_new_screen(t_struct *data)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
}
