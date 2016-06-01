/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:05:38 by daugier           #+#    #+#             */
/*   Updated: 2016/05/27 15:07:45 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ct_wds(char *str)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') && str[i])
		{
			while ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
					&& str[i])
				i++;
			j++;
		}
	}
	return (j);
}

int			ct_len_wrd(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while ((str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
		&& str[i])
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_split_space(char *str)
{
	char	**tab;
	int		k;
	int		i;
	int		j;

	i = 0;
	k = 0;
	tab = (char**)malloc(sizeof(char*) * (ct_wds(str) + 1));
	while (str[i])
	{
		j = 0;
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			tab[k] = (char*)malloc(sizeof(char) * (ct_len_wrd(&str[i]) + 1));
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i])
				tab[k][j++] = str[i++];
			tab[k][j] = '\0';
			k++;
		}
		else
			i++;
	}
	tab[k] = NULL;
	return (tab);
}
