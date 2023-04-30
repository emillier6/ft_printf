/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_pdiuxX.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emillier <emillier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:33:29 by emillier          #+#    #+#             */
/*   Updated: 2023/04/30 15:06:29 by emillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convers_di(int num, int *bcount)
{
	if (num == INT_MIN)
	{
		if (convers_s("-2147483648", bcount) == -1)
			return (-1);
	}
	else
	{
		if (num < 0)
		{
			if (convers_c('-', bcount) == -1)
				return (-1);
			num *= -1;
		}
		if (convers_ux_xup(num, bcount, 0, 10) == -1)
			return (-1);
	}
	return (*bcount);
}

int	convers_ux_xup(unsigned int num, int *bcount, int opt, unsigned int bas)
{
	char	*base;

	if (opt == 0)
		base = B10;
	if (opt == 1)
		base = B16;
	if (opt == 2)
		base = X16;
	if (num >= bas)
	{
		if (convers_ux_xup(num / bas, bcount, opt, bas) == -1)
			return (-1);
	}
	if (convers_c(base[num % bas], bcount) == -1)
		return (-1);
	return (*bcount);
}

int	showptr(unsigned long n, int *bcount)
{
	if (n >= 16)
	{
		if (showptr(n / 16, bcount) == -1)
			return (-1);
	}
	if (convers_c(B16[n % 16], bcount) == -1)
		return (-1);
	return (*bcount);
}

int	convers_p(unsigned long n, int *bcount)
{
	if (convers_s("0x", bcount) == -1)
		return (-1);
	if (showptr(n, bcount) == -1)
		return (-1);
	return (*bcount);
}
