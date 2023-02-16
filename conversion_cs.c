/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emillier <emillier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:04:03 by emillier          #+#    #+#             */
/*   Updated: 2023/02/14 17:06:13 by emillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convers_c(int c, int *bcount)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*bcount)++;
	return (*bcount);
}

int convers_s()
{

}
