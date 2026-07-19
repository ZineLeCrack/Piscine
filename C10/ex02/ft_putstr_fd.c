/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:42:21 by romain            #+#    #+#             */
/*   Updated: 2026/07/19 16:50:46 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

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
