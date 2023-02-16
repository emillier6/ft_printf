/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emillier <emillier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:04:03 by emillier          #+#    #+#             */
/*   Updated: 2023/02/16 19:29:57 by emillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	convers_c(int c, int *bcount)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*bcount)++;
	return (*bcount);
}

int convers_s(char *str, int *bcount)
{
	int i;

	if (!str)
		str = "(null)";
	i = -1;
	while (str[++i])
	{
		if (convers_c(str[i], bcount) == -1)
			return (-1);
	}
	return (*bcount);
}
