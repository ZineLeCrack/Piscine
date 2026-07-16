/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 09:42:26 by event             #+#    #+#             */
/*   Updated: 2026/07/16 09:43:40 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprintable(char c)
{
	return (' ' <= c && c <= '~');
}

int	ft_str_is_printable(char *str)
{
	if (!*str)
		return (1);
	return (ft_isprintable(*str) && ft_str_is_printable(str + 1));
}
