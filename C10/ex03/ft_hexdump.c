/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 07:54:44 by romain            #+#    #+#             */
/*   Updated: 2026/07/28 10:07:44 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_last_bytes(char buf[BUFFER_SIZE], size_t bytes_read,
			size_t total_bytes_read, int canonical)
{
	ft_print_hexa(total_bytes_read, canonical, 0);
	ft_print_on_hexa(buf, bytes_read, canonical);
	if (canonical)
		ft_print_content(buf, bytes_read);
	total_bytes_read += bytes_read;
	ft_print_hexa(total_bytes_read, canonical, 1);
	return (0);
}

int	ft_read_file(char *program_name, int fd,
			const char *filename, int canonical)
{
	ssize_t			bytes_to_read;
	static ssize_t	bytes_read = 0;
	static char		buf[BUFFER_SIZE];
	static size_t	total_bytes_read = 0;

	if (fd == -1)
		return (ft_last_bytes(buf, bytes_read, total_bytes_read, canonical));
	while (42)
	{
		bytes_to_read = BUFFER_SIZE - bytes_read;
		bytes_read += read(fd, &buf[bytes_read], bytes_to_read);
		if (bytes_read == -1)
			return (ft_putstr3_fd(basename(program_name), ": ", filename,
					STDERR_FILENO), ft_putstr3_fd("", strerror(errno),
					"\n", STDERR_FILENO), 1);
		if (bytes_read != BUFFER_SIZE)
			break ;
		ft_print_hexa(total_bytes_read, canonical, 0);
		total_bytes_read += bytes_read;
		ft_print_on_hexa(buf, bytes_read, canonical);
		if (canonical)
			ft_print_content(buf, bytes_read);
		bytes_read = 0;
	}
	return (0);
}

int	ft_handle_stdin(char *program_name, int canonical)
{
	ssize_t	bytes_read;
	ssize_t	total_bytes_read;
	char	buf[BUFFER_SIZE];

	bytes_read = 0;
	total_bytes_read = 0;
	while (42)
	{
		bytes_read = read(STDIN_FILENO,
				&buf[bytes_read], BUFFER_SIZE - bytes_read);
		if (bytes_read == -1)
			return (ft_putstr3_fd(basename(program_name), ": ", "stdin",
					STDERR_FILENO), ft_putstr3_fd("", strerror(errno),
					"\n", STDERR_FILENO), 1);
		if (bytes_read == 0)
			return (ft_print_hexa(total_bytes_read, canonical, 1), 0);
		ft_print_hexa(total_bytes_read, canonical, 0);
		total_bytes_read += bytes_read;
		ft_print_on_hexa(buf, bytes_read, canonical);
		if (canonical)
			ft_print_content(buf, bytes_read);
		bytes_read = 0;
	}
}

int	ft_open_file(char *program_name, const char *filename, int canonical)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr3_fd(basename(program_name), ": ",
			filename, STDERR_FILENO);
		ft_putstr3_fd(": ", strerror(errno), "\n", STDERR_FILENO);
		return (1);
	}
	else
	{
		ft_read_file(program_name, fd, filename, canonical);
		close(fd);
		return (0);
	}
}

int	ft_handle_arguments(int argc, char **argv, int args, int canonical)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (++i <= argc)
	{
		if (!argv[i] || argv[i][0] != '-')
		{
			if (!argv[i])
			{
				if (status == args)
				{
					ft_putstr3_fd(basename(argv[0]), "",
						": all input file arguments failed\n", STDERR_FILENO);
					return (1);
				}
				status += ft_read_file(argv[0], -1, argv[i], canonical);
			}
			else
				status += ft_open_file(argv[0], argv[i], canonical);
		}
	}
	return (status > 0);
}
