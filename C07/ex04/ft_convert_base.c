/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:32:06 by romain            #+#    #+#             */
/*   Updated: 2026/07/17 11:16:35 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_base(char *base);
int	ft_strlen(char *str);
int	ft_is_in(char c, char *str);
int	ft_get_pos(char c, char *str);
int	ft_atoi_base(char *str, char *base);

int	ft_count_size(long n, char *base)
{
	int	base_size;
	int	size;

	if (n == 0)
		return (1);
	size = n < 0;
	if (n < 0)
		n = -n;
	base_size = ft_strlen(base);
	while (n)
	{
		size++;
		n /= base_size;
	}
	return (size);
}

void	ft_fill_number(long n, char **str_ptr, char *base)
{
	int		i;
	long	copy;
	int		base_size;

	i = 0;
	if (n < 0)
		(*str_ptr)[i++] = '-';
	n *= ((2 * (n > 0)) - 1);
	base_size = ft_strlen(base);
	copy = n;
	while (copy)
	{
		i++;
		copy /= base_size;
	}
	(*str_ptr)[i] = '\0';
	while (n)
	{
		(*str_ptr)[--i] = base[n % base_size];
		n /= base_size;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*str;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	str = malloc((ft_count_size((long)n, base_to) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	ft_fill_number((long)n, &str, base_to);
	return (str);
}
