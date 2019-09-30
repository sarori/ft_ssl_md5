/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:58:52 by sapark            #+#    #+#             */
/*   Updated: 2019/09/06 18:23:05 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*p_zerohandle(t_pf *pf, char *res, int len)
{
	int		size;
	int		start;

	start = 0;
	size = 0;
	if (pf->set.dot && !pf->set.precision)
		len--;
	res = ft_memalloc_chr(len, ' ');
	res[len] = '\0';
	ft_elem(res, "0x", start, 2);
	if (!pf->set.dot)
		ft_elem(res, "0", start + 2, 2);
	if (pf->set.zero || pf->set.precision > 1)
	{
		size = pf->set.precision > 1 ? pf->set.precision - 1 : len - 1;
		start += 2;
		while (size--)
			res[start++] = '0';
	}
	ft_elem(res, "0", start, 1);
	return (res);
}

char	*p_handle(t_pf *pf, char *res, char *tmp, int len)
{
	if (!pf->set.dot && !pf->set.width)
		len += 2;
	res = ft_memalloc_chr(len, ' ');
	res[len] = '\0';
	if (pf->set.minus)
	{
		res = di_minus_handle(pf, res, tmp);
		ft_elem(res, "0x", 0, 2);
	}
	else
	{
		res = di_handle(pf, res, tmp);
		ft_elem(res, "0x", len - (int)ft_strlen(tmp) - 2, 2);
	}
	return (res);
}

void	type_p(va_list *ap, t_pf *pf)
{
	char	*res;
	char	*tmp;
	void	*ptr;
	int		len;

	ptr = va_arg(*ap, void *);
	len = cal_len(pf, (unsigned long long)ptr, 16);
	len += len < 3 ? 2 : 0;
	tmp = ft_itoa_base_u((unsigned long long)ptr, 16);
	res = NULL;
	if ((unsigned long long)ptr == 0)
	{
		len = zero_len(pf, (unsigned long long)ptr);
		res = p_zerohandle(pf, res, len);
	}
	else
		res = p_handle(pf, res, tmp, len);
	insertnode(pf, res);
	pf->res = ft_strjoinfree(pf->res, res, 1);
	free(res);
}
