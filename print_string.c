/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:19:02 by jun               #+#    #+#             */
/*   Updated: 2023/01/09 11:18:59 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_print_blank(char *format, t_flag fwp)
{
	int	print_len;
	int	format_len;

	print_len = 0;
	format_len = 0;
	format_len = ft_strlen(format);
	if (fwp.p_dot && fwp.p_prec == 0)
	{
		print_len = 0;
		format_len = 0;
	}
	else if (fwp.p_dot && fwp.p_prec < format_len)
		format_len = fwp.p_prec;
	while (format_len < fwp.w_width--)
		print_len += write(1, " ", 1);
	return (print_len);
}

int	s_print_format(char *arg_s, t_flag fwp)
{
	int	print_len;
	int	arg_s_len;

	print_len = 0;
	arg_s_len = ft_strlen(arg_s);
	if (fwp.p_dot)
	{
		if (arg_s_len <= fwp.p_prec)
		{
			while (arg_s_len--)
				print_len += write(1, arg_s++, 1);
		}
		else if (arg_s_len > fwp.p_prec)
		{
			while (fwp.p_prec--)
				print_len += write(1, arg_s++, 1);
		}
	}
	else
	{
		while (arg_s_len--)
			print_len += write(1, arg_s++, 1);
	}
	return (print_len);
}

int	print_string(char *arg_s, t_flag fwp)
{
	int	print_len;

	print_len = 0;
	if (arg_s == NULL)
		arg_s = "(null)";
	if (fwp.w_width)
	{
		if (fwp.f_minus)
		{
			print_len += s_print_format(arg_s, fwp);
			print_len += s_print_blank(arg_s, fwp);
		}
		else
		{
			print_len += s_print_blank(arg_s, fwp);
			print_len += s_print_format(arg_s, fwp);
		}
	}
	else
		print_len += s_print_format(arg_s, fwp);
	return (print_len);
}
