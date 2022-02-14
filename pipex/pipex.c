/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:17:40 by dpaper            #+#    #+#             */
/*   Updated: 2022/02/14 19:02:49 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_e(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

child_process(tube, argv, env)
{
	
}

parent_process(tube, argv, env)
{
	
}

int	main(int argc, char **argv, char **env)
{
	int		fin;
	int		fout;
	pid_t	pid;
	int		tube[2];

	if (argc != 5)
		error_e("Argument doesn't number 4");
	fin = open(argv[1], O_RDONLY);
	fout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fin == -1 || fout == -1)
		return (1);
	if (pipe(tube) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
	{
		error_e("Error fork");
	}
	if (pid == 0)
		child_process(tube, argv, env);
	else
		parent_process(tube, argv, env);
	exit(EXIT_SUCCESS);
}
