/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:32:32 by romain            #+#    #+#             */
/*   Updated: 2026/07/19 16:51:54 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

size_t	ft_strtoul(const char *str, int *status)
{
	int		i;
	size_t	n;

	n = 0;
	i = 0;
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		if (n > (ULONG_MAX - (str[i] - '0')) / 10)
		{
			ft_putstr3_fd("tail: invalid number of bytes: ‘", str,
				"’: Value too large for defined data type\n", STDERR_FILENO);
			*status = 1;
			return (0);
		}
		n = (n * 10) + (str[i++] - '0');
	}
	if (str[i])
	{
		ft_putstr3_fd("tail: invalid number of bytes: ‘",
			str, "’\n", STDERR_FILENO);
		*status = 1;
		return (0);
	}
	return (n);
}
