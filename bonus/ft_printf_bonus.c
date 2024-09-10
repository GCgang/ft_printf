/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:45:15 by hyeoan            #+#    #+#             */
/*   Updated: 2023/01/09 16:09:35 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print_len;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	print_len = my_print(format, ap);
	va_end(ap);
	if (print_len < 0)
		return (-1);
	return (print_len);
}

int	my_print(const char *format, va_list ap)
{
	t_flag	fwp;
	int		tot_len;
	int		print_len;

	tot_len = 0;
	print_len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ft_memset(&fwp, 0, sizeof(t_flag));
			if (parsing(&format, &fwp) == 0)
				return (-1);
			print_len = check_type(format, fwp, ap);
			if (print_len == -1)
				return (-1);
			tot_len += print_len;
		}
		else
			tot_len += write(1, format, 1);
		format++;
	}
	return (tot_len);
}

int	parsing(const char **format, t_flag *fwp)
{
	if (ft_strchr("-0#+ ", **format) != NULL)
		set_flag(format, fwp);
	if (ft_strchr("0123456789", **format) != NULL)
		set_width(format, fwp);
	if (**format == '.')
	{
		fwp->p_dot++;
		(*format)++;
		set_prec(format, fwp);
	}
	if (ft_strchr(DATA_TYPE, **format) != NULL)
		return (1);
	return (0);
}

int	check_type(const char *format, t_flag fwp, va_list ap)
{
	if (*format == 'c')
		return (print_char(va_arg(ap, int), fwp));
	else if (*format == '%')
		return (print_percent(*format, fwp));
	else if (*format == 's')
		return (print_string(va_arg(ap, char *), fwp));
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		return (print_diux(va_arg(ap, int), *format, fwp));
	else if (*format == 'x' || *format == 'X')
		return (print_diux(va_arg(ap, unsigned int), *format, fwp));
	else if (*format == 'p')
		return (print_p(va_arg(ap, unsigned long long), fwp));
	return (0);
}
