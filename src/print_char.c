/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 17:53:55 by jivan-de       #+#    #+#                */
/*   Updated: 2019/12/20 12:06:18 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <libft.h>
#include <unistd.h>

void			ft_print_char(t_config *cfg, va_list ap)
{
	char	c;

	cfg->i++;
	c = (char)va_arg(ap, int);
	if (cfg->min)
		cfg->len += write(1, &c, 1);
	cfg->len += print_padd(cfg->padd_char, cfg->width - 1);
	if (!cfg->min)
		cfg->len += write(1, &c, 1);
}
