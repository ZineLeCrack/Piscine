/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:54:06 by event             #+#    #+#             */
/*   Updated: 2026/07/16 13:22:22 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define HEXA "0123456789abcdef"

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	ft_print_addr(void *addr)
{
	int				i;
	char			c;
	unsigned long	ptr;

	i = 15;
	ptr = (unsigned long)addr;
	while (i >= 0)
	{
		c = HEXA[((ptr >> (i << 2)) & 0xF)];
		write(1, &c, 1);
		i--;
	}
	write(1, ": ", 2);
}

void	ft_print_on_hexa(char *str, unsigned int size)
{
	unsigned int	i;
	unsigned char	byte;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			byte = str[i];
			write(1, &HEXA[byte / 16], 1);
			write(1, &HEXA[byte % 16], 1);
		}
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_content(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (' ' <= str[i] && str[i] <= '~')
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while ((i << 4) < size)
	{
		ft_print_addr(addr + (i << 4));
		ft_print_on_hexa(addr + (i << 4), ft_min(size - (i << 4), 16));
		ft_print_content(addr + (i << 4), ft_min(size - (i << 4), 16));
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}
