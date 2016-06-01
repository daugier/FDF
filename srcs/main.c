/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:54:21 by daugier           #+#    #+#             */
/*   Updated: 2016/06/01 23:35:57 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_good_file(int ac, char **av)
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
	t_struct		*data;
	int			fd;
	
	fd = ft_check_good_file(ac, av);
	data = ft_init_struct(ac, fd, av);
	ft_fdf(data);
	return (0);
}
