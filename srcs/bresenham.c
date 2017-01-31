/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:35:35 by daugier           #+#    #+#             */
/*   Updated: 2016/10/22 16:52:52 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		write_final_line_inf(t_struct *data)
{
	int	cumul;
	int	i;

	cumul = DY / 2;
	i = 0;
	while (++i < DY + 1)
	{
		Y += YINC;
		cumul += DX;
		if (cumul > DY + 1)
		{
			cumul -= DY;
			X += XINC;
		}
		write_data_pixel(data);
	}
}

static void		write_final_line_sup(t_struct *data)
{
	int	cumul;
	int	i;

	cumul = DX / 2;
	i = 0;
	while (++i < DX + 1)
	{
		X += XINC;
		cumul += DY;
		if (cumul > DX + 1)
		{
			cumul -= DX;
			Y += YINC;
		}
		write_data_pixel(data);
	}
}

static void		write_line(t_struct *data)
{
	X = X1;
	Y = Y1;
	DX = X2 - X1;
	DY = Y2 - Y1;
	XINC = (DX > 0) ? 1 : -1;
	YINC = (DY > 0) ? 1 : -1;
	DX = abs(DX);
	DY = abs(DY);
	write_data_pixel(data);
	if (DX > DY)
		write_final_line_sup(data);
	else
		write_final_line_inf(data);
}

void			draw_line_x(t_struct *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < X_MAX - 1)
	{
		y = -1;
		while (++y < Y_MAX)
		{
			if (!COLORE)
				get_color(data, MAP[x][y]);
			X1 = define_x(data, x, y);
			X2 = define_x(data, x + 1, y);
			Y1 = define_y(data, x, y);
			Y2 = define_y(data, x + 1, y);
			write_line(data);
		}
	}
}

void			draw_line_y(t_struct *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < X_MAX)
	{
		y = -1;
		while (++y < Y_MAX - 1)
		{
			if (!COLORE)
				get_color(data, MAP[x][y]);
			X1 = define_x(data, x, y);
			X2 = define_x(data, x, y + 1);
			Y1 = define_y(data, x, y);
			Y2 = define_y(data, x, y + 1);
			write_line(data);
		}
	}
}
