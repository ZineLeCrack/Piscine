/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:47:05 by event             #+#    #+#             */
/*   Updated: 2026/07/16 13:26:03 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define HEXA "0123456789abcdef"

int	ft_isprintable(char c)
{
	return (' ' <= c && c <= '~');
}

void	ft_print_hexa(unsigned char c)
{
	char	str[3];

	str[0] = '\\';
	str[1] = HEXA[(c / 16) % 16];
	str[2] = HEXA[c % 16];
	write(1, str, 3);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isprintable(str[i]))
			write(1, &str[i], 1);
		else
			ft_print_hexa(str[i]);
		i++;
	}
}
