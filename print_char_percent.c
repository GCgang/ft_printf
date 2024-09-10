/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:16:03 by jun               #+#    #+#             */
/*   Updated: 2023/01/09 11:18:43 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_percent_print_blank(t_flag fwp, char *buf)
{
	int	print_len;

	print_len = 0;
	while (--fwp.w_width)
		print_len += write(1, buf, 1);
	return (print_len);
}

int	print_char(int arg_c, t_flag fwp)
{
	int	print_len;

	print_len = 0;
	if (fwp.w_width)
	{
		if (fwp.f_minus)
		{
			print_len += write(1, &arg_c, 1);
			print_len += c_percent_print_blank(fwp, " ");
		}
		else
		{
			print_len += c_percent_print_blank(fwp, " ");
			print_len += write(1, &arg_c, 1);
		}
	}
	else
		print_len += write(1, &arg_c, 1);
	return (print_len);
}

int	print_percent(const char format, t_flag fwp)
{
	int	print_len;

	print_len = 0;
	if (fwp.w_width)
	{
		if (fwp.f_minus)
		{
			print_len += write(1, &format, 1);
			print_len += c_percent_print_blank(fwp, " ");
		}
		else if (fwp.f_minus == 0 && fwp.f_zero > 0)
		{
			print_len += c_percent_print_blank(fwp, "0");
			print_len += write(1, &format, 1);
		}
		else
		{
			print_len += c_percent_print_blank(fwp, " ");
			print_len += write(1, &format, 1);
		}
	}
	else
		print_len += write(1, &format, 1);
	return (print_len);
}
