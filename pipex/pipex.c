/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:17:40 by dpaper            #+#    #+#             */
/*   Updated: 2022/03/21 15:19:15 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_e(char *str, int i)
{
	perror(str);
	exit(i);
}

int	ret_noexit(char *str, int i)
{
	ft_putstr_fd(str, 1);
	return (i);
}

void	child_process(int fin, int *tube, char *argv, char **env)
{
	char	*fname;
	char	**cmd;

	dup2(fin, STDIN_FILENO);
	dup2(tube[1], STDOUT_FILENO);
	close(tube[0]);
	close(fin);
	cmd = ft_split(argv, ' ');
	fname = ft_fname(cmd[0], env);
	printf ("%s", fname);
	if (fname)
	{
		if (execve(fname, cmd, env) == -1)
		{
			ft_free(cmd);
			free (fname);
			error_e("Error child", 1);
		}
	}
	else
		error_e("Command not found", 1);
	ft_free(cmd);
	free (fname);
}

void	parent_process(int fout, int *tube, char *argv, char **env)
{
	char	*fname;
	char	**cmd;

	wait(0);
	dup2(fout, STDOUT_FILENO);
	dup2(tube[0], STDIN_FILENO);
	close(tube[1]);
	close(fout);
	cmd = ft_split(argv, ' ');
	fname = ft_fname(cmd[0], env);
	if (fname)
	{
		if (execve(fname, cmd, env) < 0)
		{
			ft_free(cmd);
			free (fname);
			error_e("Error parent", 1);
		}
	}
	else
		error_e("Command not found", 1);
	ft_putstr_fd(fname, 1);
	ft_free(cmd);
	free (fname);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		tube[2];
	int		fin;
	int		fout;

	if (argc != 5)
		return (ret_noexit("Argument doesn't number 4\n", 1));
	fin = open(argv[1], O_RDONLY);
	fout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fin < 0)
		error_e("Error file input", 1);
	if (fout < 0)
		error_e("Error file output", 1);
	if (pipe(tube) == -1)
		error_e("Error pipe", 1);
	pid = fork();
	if (pid == -1)
		error_e("Error fork", 1);
	if (pid == 0)
		child_process(fin, tube, argv[2], env);
	else
		parent_process(fout, tube, argv[3], env);
	exit(EXIT_SUCCESS);
}
