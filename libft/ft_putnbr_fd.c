/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:44:44 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/18 15:20:56 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	l;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		l = -n;
	}
	else
		l = n;
	if (l > 9)
		ft_putnbr_fd(l / 10, fd);
	ft_putchar_fd(((l % 10)) + '0', fd);
	if (l % 10)
		return ;
}
