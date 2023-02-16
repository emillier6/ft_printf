/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_pdiuxX.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emillier <emillier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:33:29 by emillier          #+#    #+#             */
/*   Updated: 2023/02/16 20:12:55 by emillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convers_di(int num, int *bcount)
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
			if(convers_c('-', bcount) == -1)
				return (-1);
			num *= -1;
		}
		if (convers_uxX(num, bcount) == -1)
			return (-1);
	}
	return (*bcount);
}

int convers_uxX(unsigned int num, int *bcount, int opt, int bas)
{
	char *base;

	if (opt == 0)
		base = B10;
	if (opt == 1)
		base = B16;
	if (opt == 2)
		base = X16;

	if (num >= bas)
	{
		if (convers_uxX(num / bas, bcount, opt, bas) == -1)
			return (-1);
	}
	if (convers_c(base[num % bas], bcount) == -1)
		return (-1);
}
