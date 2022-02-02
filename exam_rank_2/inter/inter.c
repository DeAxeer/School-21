/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:14:55 by dpaper            #+#    #+#             */
/*   Updated: 2022/02/02 16:26:43 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	mass[255];

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			mass[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && !mass[argv[i][j]])
					mass[argv[i][j]] = 1;
				else if (i == 1 && mass[argv[i][j]] == 1)
				{
					mass[argv[i][j]] = 2;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i--;
		}		
	}
	write(1, "\n", 1);
}
