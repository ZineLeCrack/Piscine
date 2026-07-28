/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:32:32 by romain            #+#    #+#             */
/*   Updated: 2026/07/28 09:56:18 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

size_t	ft_strtoul(char *program_name, const char *str, int *status)
{
	int		i;
	size_t	n;

	n = 0;
	i = 0;
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		if (n > (ULONG_MAX - (str[i] - '0')) / 10)
		{
			ft_putstr_fd(basename(program_name), STDERR_FILENO);
			ft_putstr3_fd(": invalid number of bytes: ‘", str,
				"’: Value too large for defined data type\n", STDERR_FILENO);
			*status = 1;
			return (0);
		}
		n = (n * 10) + (str[i++] - '0');
	}
	if (str[i])
	{
		*status = 1;
		ft_putstr3_fd(basename(program_name), ": invalid number of bytes: ‘",
			str, STDERR_FILENO);
		return (ft_putstr_fd("’\n", STDERR_FILENO), 0);
	}
	return (n);
}
