/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:30:45 by romain            #+#    #+#             */
/*   Updated: 2026/07/19 17:04:09 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static void	ft_print_filename(const char *filename)
{
	static int	first = 1;

	if (!first)
		ft_putstr_fd("\n", STDOUT_FILENO);
	first = 0;
	ft_putstr3_fd("==> ", filename, " <==\n", STDOUT_FILENO);
}

static int	ft_read_file(const char *filename, int args, size_t bytes)
{
	int			fd;
	char		buf[BUFFER_SIZE + 1];
	char		*str;
	ssize_t		bytes_read;

	str = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr3_fd("tail: cannot open '", filename, "",
				STDERR_FILENO), ft_putstr3_fd("' for reading: ",
				strerror(errno), "\n", STDERR_FILENO), 1);
	if (args != 1)
		ft_print_filename(filename);
	while (42)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_puterr(filename), close(fd), 1);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		ft_strcat_in(&str, buf);
	}
	return (ft_putlast(str, bytes), free(str), close(fd), 0);
}

static int	ft_read_stdin(size_t bytes)
{
	char	buf[BUFFER_SIZE + 1];
	char	*str;
	ssize_t	bytes_read;

	str = NULL;
	while (42)
	{
		bytes_read = read(STDIN_FILENO, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_puterr("stdin"), 1);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		ft_strcat_in(&str, buf);
	}
	return (ft_putlast(str, bytes), free(str), 0);
}

static int	ft_get_args(char **argv, int argc, size_t *bytes, int *status)
{
	int	args;
	int	i;

	args = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] && argv[i][1] == 'c')
			{
				if (argv[i][2])
					*bytes = ft_strtoul(&argv[i][2], status);
				else
					*bytes = ft_strtoul(argv[++i], status);
			}
		}
		else
			args++;
		i++;
	}
	return (args);
}

int	main(int argc, char **argv)
{
	int		i;
	int		status;
	int		args;
	size_t	bytes;

	status = 0;
	args = ft_get_args(argv, argc, &bytes, &status);
	if (bytes == 0)
		return (0);
	if (status == 1)
		return (1);
	if (args == 0)
		return (ft_read_stdin(bytes));
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
			status |= ft_read_file(argv[i], args, bytes);
		else if (argv[i][1] && argv[i][1] == 'c' && !argv[i][2])
			i++;
		i++;
	}
	return (status);
}
