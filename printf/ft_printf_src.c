/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustyilm <mustyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:13:02 by mustyilm          #+#    #+#             */
/*   Updated: 2023/10/31 19:03:54 by mustyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putptr(unsigned long ptr, int i)
{
	int	len;
	int	tmp;

	len = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		len += 2;
	}
	if (ptr >= 16)
	{
		tmp = ft_putptr(ptr / 16, i);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789abcdef"[ptr % 16], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putnbr(int number)
{
	int	len;
	int	tmp;

	len = 0;
	if (number == 0)
		return (write(1, "0", 1));
	if (number == -2147483648)
		return (write(1, "-2147483648", 11));
	if (number < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		number *= -1;
	}
	if (number >= 10)
	{
		tmp = ft_putnbr(number / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789"[number % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_unsigned(unsigned int w)
{
	int	len;
	int	tmp;

	len = 0;
	if (w >= 10)
	{
		tmp = ft_unsigned(w / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789"[w % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_hex(unsigned int d, char w)
{
	int	len;
	int	tmp;

	len = 0;
	if (d >= 16)
	{
		tmp = ft_hex(d / 16, w);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (w == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[d % 16], 1) == -1)
			return (-1);
	}
	if (w == 'x')
	{
		if (write(1, &"0123456789abcdef"[d % 16], 1) == -1)
			return (-1);
	}
	return (len + 1);
}
