/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diux_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:02:38 by hyeoan            #+#    #+#             */
/*   Updated: 2023/01/09 16:10:04 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_blank(char *format, long long arg_diux, char type, t_flag fwp)
{
	int	format_len;
	int	print_len;

	format_len = ft_strlen(format);
	print_len = 0;
	if (type == 'u' || type == 'x' || type == 'X')
		arg_diux = (unsigned int)arg_diux;
	if (fwp.p_dot)
		print_len = pricision_ctl(format_len, arg_diux, fwp);
	else if (fwp.f_zero)
		print_len = zero_ctl(format_len, arg_diux, type, fwp);
	else
	{
		if (arg_diux < 0 || fwp.f_plus || fwp.f_space)
			format_len++;
		else if (fwp.f_hash && arg_diux != 0)
			format_len = format_len + 2;
		print_len = print_buf(format_len, fwp, " ");
	}
	return (print_len);
}

int	print_format(char *arg_s, long long arg_diux, char type, t_flag fwp)
{
	int	print_len;
	int	arg_s_len;

	print_len = 0;
	arg_s_len = ft_strlen(arg_s);
	if (fwp.p_dot)
	{
		if (fwp.p_prec == 0 && arg_diux == 0)
			return (zero_sign(arg_diux, type, fwp));
		else if (arg_diux < 0 || fwp.f_plus || fwp.f_space || fwp.f_hash)
			print_len += print_sign(arg_diux, type, fwp);
		if (arg_s_len < fwp.p_prec)
		{
			while (arg_s_len < fwp.p_prec--)
				print_len += write(1, "0", 1);
		}
	}
	else if (fwp.f_zero == 0)
		print_len = print_sign(arg_diux, type, fwp);
	while (arg_s_len--)
		print_len += write(1, arg_s++, 1);
	return (print_len);
}

int	print_diux(int arg_diux, char type, t_flag fwp)
{
	int		print_len;
	char	*num_arr;

	print_len = 0;
	num_arr = ft_itoa((long long)arg_diux, type);
	if (num_arr == NULL)
		return (-1);
	if (fwp.f_minus)
	{
		print_len += print_format(num_arr, (long long)arg_diux, type, fwp);
		print_len += print_blank(num_arr, (long long)arg_diux, type, fwp);
	}
	else
	{
		print_len += print_blank(num_arr, (long long)arg_diux, type, fwp);
		print_len += print_format(num_arr, (long long)arg_diux, type, fwp);
	}
	free(num_arr);
	return (print_len);
}
