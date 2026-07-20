/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:49:01 by romain            #+#    #+#             */
/*   Updated: 2026/07/20 17:39:52 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_print_hexa(size_t bytes_read, int canonical, int end)
{
	int		i;
	char	c;

	i = 6 + canonical;
	while (i >= 0)
	{
		c = HEXA[((bytes_read >> (i << 2)) & 0xF)];
		write(1, &c, 1);
		i--;
	}
	if (end)
		write(1, "\n", 1);
	else
		write(1, "  ", 1 + canonical);
}

void	ft_print_on_hexa(char *str, unsigned int size, int canonical)
{
	unsigned int	i;
	unsigned char	byte;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			byte = str[i + ((!canonical && (i + 1 != size) && (i % 2 == 0))
					- (!canonical && (i % 2 == 1)))];
			if (!canonical && i % 2 == 0 && i + 1 == size)
				write(1, "00", 2);
			write(1, &HEXA[byte / 16], 1);
			write(1, &HEXA[byte % 16], 1);
		}
		else
			write(1, "  ", 2);
		if (canonical || ((i % 2) && i + 1 != size))
			write(1, " ", 1);
		if (canonical && (i + 1) % 8 == 0)
			write(1, " ", 1);
		i += (!canonical && i % 2 == 0 && i + 1 == size) + 1;
	}
	if (!canonical)
		write(1, "\n", 1);
}

void	ft_print_content(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	write(1, "|", 1);
	while (i < size)
	{
		if (' ' <= str[i] && str[i] <= '~')
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|\n", 2);
}
