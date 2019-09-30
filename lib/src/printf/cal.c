/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:14:07 by sapark            #+#    #+#             */
/*   Updated: 2019/09/28 23:48:22 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

u_int64_t	cnt_flen(t_pf *pf, u_int64_t num)
{
	u_int64_t	size;
	u_int64_t	len;

	size = 0;
	size = ft_digit_base_u(num, 10) + 1;
	size += pf->set.dot == 0 ? 6 : pf->set.precision;
	if (pf->set.sign)
		size++;
	else if (pf->set.plus)
		size++;
	else if (pf->set.space)
		size++;
	len = pf->set.width > (int)size ? pf->set.width : (int)size;
	if (!pf->set.hash && pf->set.dot && !pf->set.precision)
		len--;
	return (len);
}

u_int64_t	zero_len(t_pf *pf, u_int64_t num)
{
	int	len;

	len = 0;
	if (num == 0)
	{
		if (pf->set.precision > 1)
		{
			if (pf->set.width > pf->set.precision)
				len = pf->set.width;
			else
				len = pf->set.precision + 2;
		}
		else
			len = 3;
	}
	return (len);
}

u_int64_t	cvt_num(t_pf *pf, long double num)
{
	u_int64_t	ip;
	long double	dp;
	uintmax_t	n;
	u_int64_t	size;

	ip = (u_int64_t)num;
	dp = num - (u_int64_t)num;
	size = pf->set.precision;
	if (pf->set.dot)
		size = pf->set.precision;
	else if (!pf->set.dot)
		size = 6;
	while (size-- > 0)
		dp *= 10;
	n = (uintmax_t)dp;
	n += ((uintmax_t)(dp * 10)) % 10 >= 5 ? 1 : 0;
	return (n);
}
