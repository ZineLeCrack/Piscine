/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 09:41:30 by event             #+#    #+#             */
/*   Updated: 2026/07/16 09:41:52 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isuppercase(char c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_str_is_uppercase(char *str)
{
	if (!*str)
		return (1);
	return (ft_isuppercase(*str) && ft_str_is_uppercase(str + 1));
}
