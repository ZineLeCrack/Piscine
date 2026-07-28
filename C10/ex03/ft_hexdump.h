/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:37:31 by romain            #+#    #+#             */
/*   Updated: 2026/07/28 10:07:11 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>

# define HEXA			"0123456789abcdef"
# define BUFFER_SIZE	16

int		ft_strlen(const char *str);
void	ft_putstr_fd(const char *str, const int fd);
void	ft_putstr3_fd(const char *s1, const char *s2,
			const char *s3, const int fd);
void	ft_print_hexa(size_t bytes_read, int canonical, int end);
void	ft_print_on_hexa(char *str, unsigned int size, int canonical);
void	ft_print_content(char *str, unsigned int size);
int		ft_last_bytes(char buf[BUFFER_SIZE], size_t bytes_read,
			size_t total_bytes_read, int canonical);
int		ft_read_file(char *program_name, int fd, const char *filename,
			int canonical);
int		ft_handle_stdin(char *program_name, int canonical);
int		ft_open_file(char *program_name, const char *filename, int canonical);
int		ft_handle_arguments(int argc, char **argv, int args, int canonical);

#endif
