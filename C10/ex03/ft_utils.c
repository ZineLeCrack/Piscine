/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 08:43:03 by romain            #+#    #+#             */
/*   Updated: 2026/07/20 17:40:16 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(const char *str, const int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putstr3_fd(const char *s1, const char *s2,
	const char *s3, const int fd)
{
	write(fd, s1, ft_strlen(s1));
	write(fd, s2, ft_strlen(s2));
	write(fd, s3, ft_strlen(s3));
}
