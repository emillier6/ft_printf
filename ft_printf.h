/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emillier <emillier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:00:07 by emillier          #+#    #+#             */
/*   Updated: 2023/02/16 20:12:59 by emillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

# define B10 "0123456789"
# define B16 "0123456789abdef"
# define X16 "0123456789ABCDEF"

int convers_c(int c, int *bcount);
int convers_s(char *str, int *bcount);
#endif
