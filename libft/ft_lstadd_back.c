/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:12:31 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/19 18:41:05 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copyt;

	copyt = *lst;
	if (copyt != NULL)
	{
		while (copyt -> next != NULL)
			copyt = copyt -> next;
		copyt -> next = new;
	}
	else
		*lst = new;
}
