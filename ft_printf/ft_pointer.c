/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:20:42 by dpaper            #+#    #+#             */
/*   Updated: 2021/12/03 14:14:54 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_kolnum_f(uintptr_t l)
{
	int	i;

	i = 1;
	while (l / 16)
	{
		i++;
		l /= 16;
	}
	return (i);
}

static int	ft_nine_ten(uintptr_t l)
{
	if (l % 16 >= 0 && l % 16 <= 9)
		return ('0');
	else
		return ('W');
}

static int	ft_itoa_f(void *n)
{
	int			i;
	int			j;
	char		*k;
	uintptr_t	l;

	l = (uintptr_t)n;
	i = ft_kolnum_f(l);
	j = i;
	k = (char *)malloc(sizeof(char) * (i + 1));
	if (k == (char *)0)
		return ((int)0);
	k[i] = '\0';
	while (l / 16)
	{
		k[i - 1] = (l % 16) + ft_nine_ten(l);
		l /= 16;
		i--;
	}
	k[i - 1] = l + ft_nine_ten(l);
	ft_putstr_fd(k, 1);
	free(k);
	return (j);
}

int	ft_out_p(va_list argc)
{
	void	*ptr;

	ptr = va_arg(argc, void *);
	ft_putstr_fd("0x", 1);
	return (ft_itoa_f(ptr) + 2);
}
