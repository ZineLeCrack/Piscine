/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 09:48:43 by event             #+#    #+#             */
/*   Updated: 2026/07/16 09:49:35 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isuppercase(char c)
{
	return ('A' <= c && c <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	int	i;
	int	gap;

	gap = 'a' - 'A';
	i = 0;
	while (str[i])
	{
		if (ft_isuppercase(str[i]))
			str[i] += gap;
		i++;
	}
	return (str);
}
