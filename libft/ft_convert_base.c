/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 21:07:23 by daugier           #+#    #+#             */
/*   Updated: 2016/06/12 17:32:47 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_power(int nb, int power)
{
	if (power > 1)
		return (nb * (ft_recursive_power(nb, power - 1)));
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	return (0);
}

int		ft_convert_ten(char *nbr, char *base_from)
{
	int i;
	int j;
	int l;
	int result;
	int n;

	i = ft_strlen(nbr) - 1;
	j = ft_strlen(base_from);
	result = 0;
	n = 0;
	while (i >= 0)
	{
		l = 0;
		while (base_from[l] != nbr[n])
			l++;
		result = result + l * ft_recursive_power(j, i);
		i--;
		n++;
	}
	return (result);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	str1[ft_strlen(str)];

	i = 0;
	j = 0;
	while (str[j])
	{
		str1[j] = str[j];
		j++;
	}
	j--;
	while (j >= 0)
	{
		str[i] = str1[j];
		i++;
		j--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		j;
	int		n;
	int		m;
	char	*str;

	i = ft_convert_ten(nbr, base_from);
	j = ft_strlen(base_to);
	n = 1;
	m = 0;
	while ((i = i / j) > 0)
		n++;
	str = (char*)malloc(sizeof(char) * (n + 1));
	if (ft_convert_ten(nbr, base_from) == 0)
	{
		str[m++] = '0';
		str[m] = '\0';
		return (str);
	}
	n = ft_convert_ten(nbr, base_from) * j;
	while ((n = n / j) > 0)
		str[m++] = base_to[n % j];
	str[m] = '\0';
	ft_strrev(str);
	return (str);
}
