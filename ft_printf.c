/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emillier <emillier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:11:55 by emillier          #+#    #+#             */
/*   Updated: 2023/04/30 14:44:00 by emillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char form, int *print)
{
	if (form == 'c')
		*print = convers_c(va_arg(args, int), print);
	else if (form == 's')
		*print = convers_s(va_arg(args, char *), print);
	else if (form == 'p')
		*print = convers_p(va_arg(args, unsigned long int), print);
	else if (form == 'd' || form == 'i')
		*print = convers_di(va_arg(args, int), print);
	else if (form == 'u')
		*print = convers_ux_xup(va_arg(args, unsigned int), print, 0, 10);
	else if (form == 'x')
		*print = convers_ux_xup(va_arg(args, unsigned int), print, 1, 16);
	else if (form == 'X')
		*print = convers_ux_xup(va_arg(args, unsigned int), print, 2, 16);
	else if (form == '%')
		*print = convers_c('%', print);
	return (*print);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			res = ft_formats(arg, str[i + 1], &res);
			i++;
		}
		else
			res = convers_c(str[i], &res);
		i++;
	}
	va_end(arg);
	return (res);
}
