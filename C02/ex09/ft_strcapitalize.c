/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 09:50:20 by event             #+#    #+#             */
/*   Updated: 2026/07/16 09:56:19 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isuppercase(char c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_islowercase(char c)
{
	return ('a' <= c && c <= 'z');
}

int	ft_isnumeric(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isalphanum(char c)
{
	return (ft_islowercase(c) || ft_isuppercase(c) || ft_isnumeric(c));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || !ft_isalphanum(str[i - 1]))
		{
			if (ft_islowercase(str[i]))
				str[i] -= 32;
		}
		else
		{
			if (ft_isuppercase(str[i]))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
