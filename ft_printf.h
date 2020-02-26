/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 14:56:46 by jivan-de       #+#    #+#                */
/*   Updated: 2020/01/07 12:37:18 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>

typedef struct			s_struct
{
	size_t				i;
	int					padd;
	char				padd_dir;
	char				padd_char;
	int					prec;
	int					prec_zero;
	int					prec_neg;
	int					len;
	int					upper;
	int					sign;
	int					min;
	int					width;
	int					zero;
	int					error;
}						t_config;

int						ft_printf(const char *format, ...);
void					parse(const char *format, t_config *cfg, va_list ap);
t_config				*cfg_init(void);
void					cfg_reset(t_config *cfg);
void					printer(const char *format, t_config *cfg, va_list ap);
void					print_pcnt(t_config *cfg);
int						print_padd(char c, int count);
void					ft_print_num(t_config *cfg, va_list ap);
void					ft_print_hex(const char *format, t_config *cfg, \
							va_list ap);
void					ft_print_char(t_config *cfg, va_list ap);
void					ft_print_string(t_config *cfg, va_list ap);
void					ft_print_uint(t_config *cfg, va_list ap);
void					ft_print_pointer(t_config *cfg, va_list ap);
void					print_clear(t_config *cfg);
void					ft_error(t_config *cfg);

#endif
