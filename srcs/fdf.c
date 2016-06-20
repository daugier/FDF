/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:00:26 by daugier           #+#    #+#             */
/*   Updated: 2016/06/19 19:06:35 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_color(char *str)
{
	int		i;
	int		j;
	int		color_value;
	char	*tmp;
	char	*color;

	i = 0;
	j = 0;
	while (str[i] != ',' && str[i])
		i++;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(str + i) + 1)))
		return (0);
	while (str[i])
		tmp[j++] = str[i++];
	color = ft_convert_base(tmp, "HEXA", "DECI");
	color_value = ft_atoi(color);
	return (color_value);
}

void	ft_img_put_pixel(t_struct *data, int x, int y, unsigned int color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	b = (color & 0xFF0000 >> 16);
	g = (color & 0xFF00 >> 8);
	r = (color & 0xFF);
	DATA[y * SIZE_LINE + x * (BPP / 8)] = r;
	DATA[y * SIZE_LINE + x * (BPP / 8) + 1] = g;
	DATA[y * SIZE_LINE + x * (BPP / 8) + 2] = b;
}

int		ft_fdf(t_struct *data, t_point *p)
{
	int				y;
	int				x;
	int				color;

	ft_init_point(p);
	x = 0;
	while (MAP[x])
	{
		y = 0;
		while (MAP[x][y])
		{
			color = ft_get_color(MAP[x][y]);
			if (!(color = ft_get_color(MAP[x][y])))
				color = 0xFFFFFF * ft_atoi(MAP[x][y]);
			COLOR = mlx_get_color_value(MLX, color);
			ft_img_put_pixel(data, y * ZOOM, x * ZOOM, COLOR);
			y++;
		}
		x++;
	}
	PUT_IMG = mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}
