/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 09:54:39 by romain            #+#    #+#             */
/*   Updated: 2026/07/28 09:06:21 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_create_str(int size, char **strs, char *sep)
{
	int		i;
	int		sep_len;
	int		total_len;
	char	*str;

	if (size == 0)
		return (malloc(1));
	i = 0;
	total_len = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
		total_len += ft_strlen(strs[i++]);
	total_len += (size - 1) * sep_len;
	str = malloc((total_len + 1) * sizeof(char));
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*str;

	if (size < 0)
		return (NULL);
	str = ft_create_str(size, strs, sep);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		ft_strcpy(&str[j], strs[i]);
		j += ft_strlen(strs[i]);
		i++;
		if (i != size)
		{
			ft_strcpy(&str[j], sep);
			j += ft_strlen(sep);
		}
	}
	str[j] = '\0';
	return (str);
}
