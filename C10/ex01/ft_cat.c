/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:30:45 by romain            #+#    #+#             */
/*   Updated: 2026/07/18 18:17:22 by romain           ###   ########.fr       */
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

void	ft_puterr(const char *filename)
{
	ft_putstr_fd("cat: ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

int	ft_display_file(const char *filename)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_puterr(filename);
		return (1);
	}
	while (42)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_puterr(filename);
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

int	ft_display_stdin(void)
{
	char	buf[BUFFER_SIZE];
	ssize_t	bytes_read;

	while (42)
	{
		bytes_read = read(0, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_puterr("stdin");
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
		return (ft_display_stdin());
	i = 1;
	status = 0;
	while (i < argc)
		status |= ft_display_file(argv[i++]);
	return (status);
}
