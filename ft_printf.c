/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 14:58:27 by jivan-de       #+#    #+#                */
/*   Updated: 2019/12/19 15:13:52 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int					ft_printf(const char *format, ...)
{
	va_list		ap;
	t_config	*cfg;
	int			len;

	len = ft_strlen(format);
	if (len == 0 || (len == 1 && format[0] == '%'))
		return (0);
	if (ft_strchr(format, '%'))
	{
		cfg = cfg_init();
		if (cfg == NULL)
			return (-1);
		va_start(ap, format);
		parse(format, cfg, ap);
		va_end(ap);
		len = cfg->len;
		if (cfg->error != 0)
			len = -1;
		free(cfg);
		return (len);
	}
	else
		return (write(1, format, len));
}
