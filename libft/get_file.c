/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 23:55:34 by daugier           #+#    #+#             */
/*   Updated: 2016/06/20 18:17:02 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_file(char *av, char **str)
{
	int		fd;
	char	*tmp;

	if (!(*str = (char*)malloc(sizeof(char) * 1)))
		return (0);
	*str[0] = '\0';
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	if (get_next_line((int const)fd, &tmp) == -1)
		return (-1);
	*str = ft_strjoin_f(*str, tmp);
	*str = ft_strjoin_f(*str, "\n");
	free(tmp);
	tmp = NULL;
	while (get_next_line((int const)fd, &tmp))
	{
		*str = ft_strjoin_f(*str, tmp);
		*str = ft_strjoin_f(*str, "\n");
		free(tmp);
		tmp = NULL;
	}
	close(fd);
	return (1);
}
