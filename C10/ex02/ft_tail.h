/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:03:57 by romain            #+#    #+#             */
/*   Updated: 2026/07/28 09:52:06 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 1024

int		ft_strlen(const char *str);
void	ft_putstr_fd(const char *str, const int fd);
void	ft_putstr3_fd(const char *s1, const char *s2,
			const char *s3, const int fd);
size_t	ft_strtoul(char *program_name, const char *str, int *status);
void	ft_puterr(char *program_name, const char *filename);
void	ft_strcat_in(char **str_ptr, char buf[BUFFER_SIZE]);
void	ft_putlast(const char *str, ssize_t bytes);

#endif
