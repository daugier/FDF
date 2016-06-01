/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:30:09 by daugier           #+#    #+#             */
/*   Updated: 2016/06/01 23:25:05 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H_
# define FDF_H_

# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "../libft/include/libft.h"

# define MLX data->mlx
# define WIN data->win
# define X data->x
# define Y data->y
# define Z data->z
# define E1 data->e1
# define E2 data->e2
# define MAP data->map

typedef struct	s_struct
{
	void	*mlx;
	void	*win;
	char	***map;
	int		e1;
	int		e2;
	int		x;
	int		y;
	int		z;
}				t_struct;

void			ft_stock_map(int fd, t_struct *data);
t_struct		*ft_init_struct(int ac, int fd, char **av);
void			ft_fdf(t_struct *data);

#endif
