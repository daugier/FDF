/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:30:09 by daugier           #+#    #+#             */
/*   Updated: 2016/06/01 12:11:41 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H_
# define FDF_H_

#include <mlx.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"

# define MLX param->mlx
# define WIN param->win
# define X param->x
# define Y param->y
# define E1 param->e1
# define E2 param->e2

typedef struct	s_struct
{
	void	*mlx;
	void	*win;
	int		e1;
	int		e2;
}				t_struct;

#endif
