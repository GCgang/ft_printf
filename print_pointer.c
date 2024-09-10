/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:31:05 by jun               #+#    #+#             */
/*   Updated: 2023/01/09 11:31:50 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_zero(t_flag fwp)
{
	int	print_len;

	print_len = 0;
	if (fwp.f_minus)
	{
		print_len += write(1, "0x0", 3);
		print_len += print_buf(3, fwp, " ");
	}
	else
	{
		print_len += print_buf(3, fwp, " ");
		print_len += write(1, "0x0", 3);
	}
	return (print_len);
}

int	p_len(unsigned long long arg_p)
{
	int	size;

	size = 0;
	while (arg_p > 0)
	{
		arg_p /= 16;
		size++;
	}
	return (size);
}

int	print_p(unsigned long long arg_p, t_flag fwp)
{
	int					print_len;
	int					size;

	print_len = 0;
	size = 0;
	if (arg_p == 0)
		return (p_zero(fwp));
	size = p_len(arg_p);
	if (fwp.f_minus)
	{
		write(1, "0x", 2);
		print_pointer(arg_p);
		print_len += print_buf(size + 2, fwp, " ");
	}
	else
	{
		print_len += print_buf(size + 2, fwp, " ");
		write(1, "0x", 2);
		print_pointer(arg_p);
	}
	return (print_len + size + 2);
}

void	print_pointer(unsigned long long nb)
{
	int	print_len;

	print_len = 0;
	if (nb > 15)
	{
		print_pointer(nb / 16);
		print_pointer(nb % 16);
	}
	else
		write(1, &"0123456789abcdef"[nb], 1);
}
