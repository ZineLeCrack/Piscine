/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:30:45 by romain            #+#    #+#             */
/*   Updated: 2026/07/18 17:46:54 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void	ft_putstr_fd(const char *str, const int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

int	ft_display_file(const char *filename)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot read file.\n", STDERR_FILENO);
		return (1);
	}
	while (42)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_putstr_fd("Cannot read file.\n", STDERR_FILENO);
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

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("File name missing.\n", STDERR_FILENO);
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Too many arguments.\n", STDERR_FILENO);
		return (1);
	}
	return (ft_display_file(argv[1]));
}
