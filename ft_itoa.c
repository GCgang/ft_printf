/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:05:53 by hyeoan            #+#    #+#             */
/*   Updated: 2023/01/06 19:39:04 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(long long nb, char type)
{
	char		*str;
	size_t		size;

	if (nb < I_MIN || I_MAX < nb)
		return (NULL);
	if (type == 'u' || type == 'x' || type == 'X')
		nb = (unsigned int)nb;
	if (nb < 0)
		nb *= -1;
	size = get_size(nb, type);
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = make_num(nb, str, size, type);
	return (str);
}

size_t	get_size(long long nb, char type)
{
	size_t	size;

	size = 0;
	if (nb == 0)
		return (1);
	if (type == 'x' || type == 'X')
	{
		while (nb > 0)
		{
			nb /= 16;
			size++;
		}
	}
	else
	{
		while (nb > 0)
		{
			nb /= 10;
			size++;
		}
	}
	return (size);
}

char	*make_num(long long nb, char *str, size_t size, char type)
{
	if (type == 'x')
	{
		while (nb > 0)
		{
			str[--size] = "0123456789abcdef"[nb % 16];
			nb /= 16;
		}
	}
	else if (type == 'X')
	{
		while (nb > 0)
		{
			str[--size] = "0123456789ABCDEF"[nb % 16];
			nb /= 16;
		}
	}
	else
	{
		while (nb > 0)
		{
			str[--size] = '0' + (nb % 10);
			nb /= 10;
		}
	}
	return (str);
}
