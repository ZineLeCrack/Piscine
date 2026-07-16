/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 09:44:13 by event             #+#    #+#             */
/*   Updated: 2026/07/16 09:48:25 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_islowercase(char c)
{
	return ('a' <= c && c <= 'z');
}

char	*ft_strupcase(char *str)
{
	int	i;
	int	gap;

	gap = 'A' - 'a';
	i = 0;
	while (str[i])
	{
		if (ft_islowercase(str[i]))
			str[i] += gap;
		i++;
	}
	return (str);
}
