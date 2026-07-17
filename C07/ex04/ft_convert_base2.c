/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:40:56 by romain            #+#    #+#             */
/*   Updated: 2026/07/17 10:40:58 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (!base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (('\t' <= base[i] && base[i] <= '\r') || base[i] == ' '))
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

int	ft_is_in(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_get_pos(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	len;
	int	sign;
	int	pos;

	if (!ft_check_base(base))
		return (0);
	i = 0;
	n = 0;
	sign = 1;
	len = ft_strlen(base);
	while (str[i] && (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		sign *= ((str[i++] != '-') * 2) - 1;
	while (42)
	{
		pos = ft_get_pos(str[i++], base);
		if (pos == -1)
			break ;
		n *= len;
		n += pos;
	}
	return (n * sign);
}
