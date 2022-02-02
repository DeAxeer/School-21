/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:15:40 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/10 17:38:33 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	while ((*(s1 + k) != '\0') && (n > k))
	{
		if ((*(unsigned char *)(s1 + k) - *(unsigned char *)(s2 + k)) != 0)
			return (*(unsigned char *)(s1 + k) - *(unsigned char *)(s2 + k));
		k++;
	}
	k = 0;
	while (*(unsigned char *)(s2 + k) != '\0' && (n > k))
	{
		if ((*(unsigned char *)(s1 + k) - *(unsigned char *)(s2 + k)) != 0)
			return (*(unsigned char *)(s1 + k) - *(unsigned char *)(s2 + k));
		k++;
	}
	return (0);
}
