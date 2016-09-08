/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:00:26 by daugier           #+#    #+#             */
/*   Updated: 2016/09/08 15:01:59 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		define_x(t_struct *data, int x, int y)
{
	return ((ZOOM * (y - x) + (WIDTH / 2 + W_PIC)));
}

int		define_y(t_struct *data, int x, int y)
{
	Z = TOP * ft_atoi(MAP[x][y]);
	if (!COLOR || COLORE == 2)
	{
		if (Z > 100)
			COLOR = mlx_get_color_value(MLX, COLOR + 0xFF0000);
		if (Z <= 100 && Z > 40)
			COLOR = mlx_get_color_value(MLX, COLOR + 0xFF3300);
		if (Z <= 40 && Z > 0)
			COLOR = mlx_get_color_value(MLX, COLOR + 0xFF6600);
		if (Z <= 0 && Z > -20)
			COLOR = mlx_get_color_value(MLX, COLOR + 0xFF9900);
		if (Z <= -20)
			COLOR = mlx_get_color_value(MLX, COLOR + 0xFFCC00);
	}
	return ((ZOOM * (CT1 / A * y + CT2 / A * x) - Z) + (HEIGHT / 3 + H_PIC));
}

void	get_color(t_struct *data, char *str)
{
	int					i;
	int					j;
	char				*tmp;
	char				*color;

	i = 0;
	j = 0;
	while (str[i] != ',' && str[i])
		i++;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(str + i) + 1)))
		return ;
	i += 3;
	while (str[i])
		tmp[j++] = str[i++];
	color = ft_convert_base(tmp, HEXA, DECI);
	COLOR = ft_atoi(color);
}

void	write_data_pixel(t_struct *data)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (COLOR)
	{
		b = (COLOR & 0xFF0000) >> 16;
		g = (COLOR & 0xFF00) >> 8;
		r = (COLOR & 0xFF);
	}
	if (X >= 0 && Y >= 0 && X < WIDTH && Y < HEIGHT)
	{
		DATA[Y * SIZE_LINE + X * (BPP / 8)] = r;
		DATA[Y * SIZE_LINE + X * (BPP / 8) + 1] = g;
		DATA[Y * SIZE_LINE + X * (BPP / 8) + 2] = b;
	}
}

int		ft_fdf(t_struct *data)
{
	draw_line_x(data);
	draw_line_y(data);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	write_screen(data);
	return (0);
}
