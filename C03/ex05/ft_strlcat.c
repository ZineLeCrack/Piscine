/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:03:03 by romain            #+#    #+#             */
/*   Updated: 2026/07/16 14:18:55 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_min(unsigned int a, unsigned int b)
{
	if (b < a)
		return (b);
	return (a);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	len = ft_min(ft_strlen(dest), size) + ft_strlen(src);
	i = 0;
	while (dest[i] && i < size)
		i++;
	if (i == size)
		return (len);
	j = 0;
	while (src[j] && i + 1 < size)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (len);
}
