/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:45:19 by hyeoan            #+#    #+#             */
/*   Updated: 2023/01/09 16:09:56 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	set_flag(const char **format, t_flag *fwp)
{
	while (ft_strchr("-0#+ ", **format) != NULL)
	{
		if (**format == '-')
			fwp->f_minus++;
		else if (**format == '0')
			fwp->f_zero++;
		else if (**format == '#')
			fwp->f_hash++;
		else if (**format == '+')
			fwp->f_plus++;
		else if (**format == ' ')
			fwp->f_space++;
		(*format)++;
	}
}

void	set_width(const char **format, t_flag *fwp)
{
	while (ft_isdigit(**format) != 0)
	{
		fwp->w_width *= 10;
		fwp->w_width += (**format - '0');
		(*format)++;
	}
}

void	set_prec(const char **format, t_flag *fwp)
{
	while (ft_isdigit(**format) != 0)
	{
		fwp->p_prec *= 10;
		fwp->p_prec += (**format - '0');
		(*format)++;
	}
}
