/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diuxp_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:55:07 by hyeoan            #+#    #+#             */
/*   Updated: 2023/01/09 11:42:18 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_buf(int format_len, t_flag fwp, char *buf)
{
	int	print_len;

	print_len = 0;
	while (format_len < fwp.w_width--)
		print_len += write(1, buf, 1);
	return (print_len);
}

int	zero_sign(long long arg_diux, char type, t_flag fwp)
{
	int	print_len;

	print_len = 0;
	if (fwp.f_plus)
		print_len += print_sign(arg_diux, type, fwp);
	else if (fwp.f_space > 0 && fwp.f_plus == 0)
		print_len += print_sign(arg_diux, type, fwp);
	else if (fwp.f_hash && fwp.w_width)
		print_len += write(1, " ", 1);
	return (print_len);
}

int	pricision_ctl(int format_len, long long arg_diux, t_flag fwp)
{
	int	print_len;

	print_len = 0;
	if (format_len < fwp.p_prec)
		format_len = fwp.p_prec;
	if (arg_diux < 0 || fwp.f_plus || fwp.f_space)
		format_len++;
	else if (fwp.f_hash && arg_diux != 0)
		format_len += 2;
	if (arg_diux == 0 && fwp.p_prec == 0 && fwp.f_hash == 0)
		format_len--;
	print_len = print_buf(format_len, fwp, " ");
	return (print_len);
}

int	zero_ctl(int format_len, long long arg_diux, char type, t_flag fwp)
{
	int	sign_len;
	int	print_len;

	sign_len = 0;
	print_len = 0;
	sign_len += print_sign(arg_diux, type, fwp);
	format_len = format_len + sign_len;
	print_len = print_buf(format_len, fwp, "0");
	return (print_len + sign_len);
}

int	print_sign(long long arg_diux, char type, t_flag fwp)
{
	int	print_len;

	print_len = 0;
	if (type == 'd' || type == 'i')
	{
		if (arg_diux < 0)
			print_len += write(1, "-", 1);
		else if (fwp.f_plus > 0)
			print_len += write(1, "+", 1);
		else if (fwp.f_space > 0)
			print_len += write(1, " ", 1);
	}
	else if (type == 'x' || type == 'X')
	{
		if (type == 'x' && fwp.f_hash && arg_diux != 0)
			print_len += write(1, "0x", 2);
		else if (type == 'X' && fwp.f_hash && arg_diux != 0)
			print_len += write(1, "0X", 2);
	}
	return (print_len);
}
