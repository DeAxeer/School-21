/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:08:29 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/10 15:39:47 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	n;
	unsigned int	a;

	n = 0;
	a = 0;
	while (*str == 32 || *str == '\f' || *str == '\r'
		|| *str == '\t' || *str == '\v' || *str == '\n')
		str++;
	if (*str != '\0' && (*str == 45 || *str == 43))
	{
		if (*str == 45)
			n++;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		a = a * 10 + (*str - 48);
		str++;
	}
	if (n % 2)
		a = -a;
	return (a);
}
