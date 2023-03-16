/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emillier <emillier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:11:55 by emillier          #+#    #+#             */
/*   Updated: 2023/02/14 15:14:08 by emillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_formats(va_list args, const char form)
{
    int print;

    print = 0;
    if (form == 'c')
		print = convers_c(va_arg(args, int), print);
	else if (form == 's')
		print = convers_s(va_arg(args, char *), print);
	else if (form == 'p')
		print = ;
	else if (form == 'd' || form == 'i')
		print = convers_di(va_arg(args, int), print);
	else if (form == 'x' || form == 'X' || form == 'u')
		print = convers_uxX(va_arg(args, unsigned int), print, );
	else if (form == '%')
		print = convers_c(va_arg(args, int), print);
	return (print);
}
int ft_printf(char const *str, ...)
{
    va_list arg;
    int i;
    int res;

    i = 0;
    res = 0;
    va_start(arg, str);
    while(str[i])
    {
        if(str[i] == '%')
        {
            res = ft_formats(arg, str[i+1]);
            i++;
        }
        else
            res = convers_c(s[i], res);
        i++;
    }
    va_end(arg);
    return (res);
}
