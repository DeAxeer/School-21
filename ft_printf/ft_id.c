/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:45:41 by dpaper            #+#    #+#             */
/*   Updated: 2021/12/03 14:14:54 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_kolnum_id(int l)
{
	int	i;

	i = 1;
	if (l < 0)
	{
		l = -l;
		i++;
	}
	while (l / 10)
	{
		i++;
		l /= 10;
	}
	return (i);
}

static void	ft_deldec(char *k, int l, int i)
{
	k[i] = '\0';
	while (l / 10)
	{
		k[i - 1] = (l % 10) + '0';
		l /= 10;
		i--;
	}
	k[i - 1] = l + '0';
}

static int	ft_itoa_id(int l)
{
	int		i;
	char	*k;

	if (l == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	}
	i = ft_kolnum_id(l);
	k = (char *)malloc(sizeof(char) * (i + 1));
	if (k == (char *)0)
		return ((int)0);
	if (l < 0)
	{
		l = -l;
		k[0] = '-';
	}
	ft_deldec(k, l, i);
	ft_putstr_fd(k, 1);
	free(k);
	return (i);
}

int	ft_out_id(va_list argc)
{
	int	id;

	id = va_arg(argc, int);
	return (ft_itoa_id(id));
}
