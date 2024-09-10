/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:45:11 by hyeoan            #+#    #+#             */
/*   Updated: 2023/01/09 11:51:08 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define DATA_TYPE "csdiupxX%"
# define I_MIN -2147483648
# define I_MAX 2147483647

typedef struct s_flag
{
	int		percent;
	int		f_minus;
	int		f_zero;
	int		f_hash;
	int		f_plus;
	int		f_space;
	int		w_width;
	int		p_dot;
	int		p_prec;
	char	type;
}	t_flag;
// ft_printf
int		ft_printf(const char *format, ...);
int		my_print(const char *format, va_list ap);
int		parsing(const char **format, t_flag *fwp);
int		check_type(const char *format, t_flag fwp, va_list ap);
// parse
void	set_flag(const char **format, t_flag *fwp);
void	set_width(const char **format, t_flag *fwp);
void	set_prec(const char **format, t_flag *fwp);
// util
int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
// c %
int		c_percent_print_blank(t_flag fwp, char *buf);
int		print_char(int arg_c, t_flag fwp);
int		print_percent(const char format, t_flag fwp);
// s
int		s_print_blank(char *format, t_flag fwp);
int		s_print_format(char *arg_s, t_flag fwp);
int		print_string(char *arg_s, t_flag fwp);
// diuxX
int		print_blank(char *format, long long arg_diux, char type, t_flag fwp);
int		print_format(char *arg_s, long long arg_diux, char type, t_flag fwp);
int		print_diux(int arg_diux, char type, t_flag fwp);
// dixXp_util
int		print_buf(int format_len, t_flag fwp, char *buf);
int		zero_sign(long long arg_diux, char type, t_flag fwp);
int		pricision_ctl(int format_len, long long arg_diux, t_flag fwp);
int		zero_ctl(int format_len, long long arg_diux, char type, t_flag fwp);
int		print_sign(long long arg_diux, char type, t_flag fwp);
// itoa
char	*ft_itoa(long long nb, char type);
size_t	get_size(long long nb, char type);
char	*make_num(long long nb, char *str, size_t size, char type);
// pointer
int		p_zero(t_flag fwp);
int		p_len(unsigned long long arg_p);
int		print_p(unsigned long long arg_p, t_flag fwp);
void	print_pointer(unsigned long long nb);

#endif