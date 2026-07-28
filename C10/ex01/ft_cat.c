/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:30:45 by romain            #+#    #+#             */
/*   Updated: 2026/07/28 09:41:31 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

#define BUFFER_SIZE 1024

void	ft_putstr_fd(const char *str, const int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

void	ft_puterr(char *program_name, const char *filename)
{
	ft_putstr_fd(basename(program_name), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

int	ft_display_file(char *program_name, const char *filename)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_puterr(program_name, filename);
		return (1);
	}
	while (42)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_puterr(program_name, filename);
			close(fd);
			return (1);
		}
		if (bytes_read == 0)
			break ;
		write(STDOUT_FILENO, buf, bytes_read);
	}
	close(fd);
	return (0);
}

int	ft_display_stdin(char *program_name)
{
	char	buf[BUFFER_SIZE];
	ssize_t	bytes_read;

	while (42)
	{
		bytes_read = read(STDIN_FILENO, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_puterr(program_name, "stdin");
			return (1);
		}
		if (bytes_read == 0)
			break ;
		write(STDOUT_FILENO, buf, bytes_read);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	status;

	if (argc == 1)
		return (ft_display_stdin(argv[0]));
	i = 1;
	status = 0;
	while (i < argc)
		status |= ft_display_file(argv[0], argv[i++]);
	return (status);
}
