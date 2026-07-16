/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:51:01 by romain            #+#    #+#             */
/*   Updated: 2026/07/16 17:53:17 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (!base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base_print(long n, char *base, int base_size)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < base_size)
		write(1, &base[n], 1);
	else
	{
		ft_putnbr_base_print(n / base_size, base, base_size);
		ft_putnbr_base_print(n % base_size, base, base_size);
	}
}

void	ft_putnbr_base(int n, char *base)
{
	if (!ft_check_base(base))
		return ;
	ft_putnbr_base_print((long)n, base, ft_strlen(base));
}
