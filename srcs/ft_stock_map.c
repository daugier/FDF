/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:50:45 by daugier           #+#    #+#             */
/*   Updated: 2016/06/01 22:30:38 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_stock_map(int fd, t_struct *data)
{
	char	*buffer;
	char	**buff;
	int		x;

	x = 0;
	if (!(buffer = ft_getmap(fd)))
		exit(EXIT_FAILURE);
	if (!(MAP = (char***)ft_memalloc(sizeof(char**) *
					ft_lenchar(buffer, '\n') + 1)))
		exit(EXIT_FAILURE);
	if (!(buff = ft_strsplit(buffer, '\n')))
		exit(EXIT_FAILURE);
	while (buff[x])
	{
		MAP[x] = ft_strsplit(buff[x], ' ');
		x++;
	}
	MAP[x] = NULL;
}

t_struct	*ft_init_struct(int ac, int fd, char **av)
{
	t_struct	*data;

	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		exit(EXIT_FAILURE);
	ft_stock_map(fd, data);
	if (ac == 4)
	{
		E1 = ft_atoi(av[2]);
		E2 = ft_atoi(av[3]);
	}
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 1200, 800, av[1]);
	return (data);
}
