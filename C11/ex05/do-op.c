/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 09:13:45 by romain            #+#    #+#             */
/*   Updated: 2026/07/21 09:47:27 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

int	ft_add(int a, int b);
int	ft_sub(int a, int b);
int	ft_mul(int a, int b);
int	ft_div(int a, int b);
int	ft_mod(int a, int b);

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	n;

	n = 0;
	i = 0;
	sign = 1;
	while (str[i] && (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		sign *= ((str[i++] != '-') * 2) - 1;
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		n *= 10;
		n += str[i++] - '0';
	}
	return (n * sign);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_do_op(int n1, char *op, int n2)
{
	static int	(*functions[])(int, int) = {
		ft_add, ft_sub, ft_mul, ft_div, ft_mod};

	if (op[0] == '+' && !op[1])
		ft_putnbr(functions[0](n1, n2));
	else if (op[0] == '-' && !op[1])
		ft_putnbr(functions[1](n1, n2));
	else if (op[0] == '*' && !op[1])
		ft_putnbr(functions[2](n1, n2));
	else if (op[0] == '/' && !op[1])
	{
		if (!n2)
			return (write(STDERR_FILENO, "Stop : division by zero\n", 24));
		ft_putnbr(functions[3](n1, n2));
	}
	else if (op[0] == '%' && !op[1])
	{
		if (!n2)
			return (write(STDERR_FILENO, "Stop : modulo by zero\n", 22));
		ft_putnbr(functions[4](n1, n2));
	}
	else
		write(STDOUT_FILENO, "0", 1);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		return (ft_do_op(ft_atoi(argv[1]), argv[2], ft_atoi(argv[3])) != 0);
	else
		return (1);
}
