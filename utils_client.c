/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:37:26 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/12 14:49:12 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

size_t	ft_putchar_len(char c)
{
	write (1, &c, 1);
	return (1);
}

size_t	ft_putstr_len(char	*str)
{
	size_t	i;

	i = 0;
	if (!str || str == NULL)
	{
		i += ft_putstr_len("(null)");
		return (i);
	}
	while (str[i] != '\0')
	{
		ft_putchar_len(str[i]);
		i++;
	}
	return (i);
}

size_t	ft_putnbr_len(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstr_len("-2147483648");
		return (len);
	}
	if (n < 0)
	{
		n = -n;
		len += ft_putchar_len('-');
	}
	while (n >= 10)
	{
		len += ft_putnbr_len(n / 10);
		break ;
	}
	len += ft_putchar_len(n % 10 + '0');
	return (len);
}

long long	ft_to_max_min(unsigned long long out, long long g, const char *str)
{
	if (str[g] == '-')
	{
		if (out > 9223372036854775807)
			return (0);
		return (-out);
	}
	if (out > 9223372036854775806)
		return (-1);
	return (out);
}

int	ft_atoi(const char *str)
{
	long long	out;
	long long	i;
	long long	g;

	i = 0;
	out = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 9) || (str[i] > 13 && str[i] != 32))
			break ;
		i++;
	}
	g = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		out = out * 10 + (str[i] - '0');
		i++;
	}
	return (ft_to_max_min(out, g, str));
}
