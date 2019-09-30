/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 02:15:04 by sapark            #+#    #+#             */
/*   Updated: 2019/09/07 01:55:52 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flaghandle(t_pf *pf, char *res)
{
	if (pf->set.space || pf->set.plus)
	{
		if (pf->set.space && !pf->set.sign)
			ft_elem(res, " ", 0, 1);
		else if (pf->set.plus && !pf->set.sign)
			ft_elem(res, "+", 0, 1);
	}
	if (pf->set.sign)
		ft_elem(res, "-", 0, 1);
}

void			type_f(va_list *ap, t_pf *pf)
{
	long double	f;
	char		*res;
	u_int64_t	len;

	f = get_arg_f(ap, pf);
	pf->set.sign = f < 0 ? 1 : 0;
	f = f < 0 ? f * -1 : f;
	len = cnt_flen(pf, f);
	res = ft_memalloc_chr(len, ' ');
	res[len] = '\0';
	if (pf->set.minus)
		f_minus_handle(pf, res, f);
	else
		f_handle(pf, res, f);
	insertnode(pf, res);
	pf->res = ft_strjoinfree(pf->res, res, 1);
	free(res);
}

char			*f_handle(t_pf *pf, char *res, long double num)
{
	u_int64_t	dp;
	char		*ip_tmp;
	char		*dp_tmp;
	int			start;
	int			size;

	dp = cvt_num(pf, num);
	ip_tmp = ft_itoa_base_u((u_int64_t)num, 10);
	dp_tmp = ft_itoa_base_u(dp, 10);
	size = (pf->set.dot) ? pf->set.precision : 6;
	start = (int)(ft_strlen(res) - (!dp ? 1 : ft_strlen(dp_tmp)));
	if (dp)
		ft_elem(res, dp_tmp, start--, ft_strlen(dp_tmp));
	else
	{
		while (size--)
			res[start--] = '0';
		start -= size;
	}
	if (pf->set.hash || !pf->set.dot || pf->set.precision)
		ft_elem(res, ".", start, 1);
	start -= (int)ft_strlen(ip_tmp);
	ft_elem(res, ip_tmp, start, (int)ft_strlen(ip_tmp));
	res = f_zero_handle(pf, res, start, size);
	return (res);
}

char			*f_zero_handle(t_pf *pf, char *res, int start, int size)
{
	if (pf->set.zero)
	{
		size = start;
		while (size--)
		{
			res[start - 1] = '0';
			start--;
		}
		flaghandle(pf, res);
	}
	else
	{
		if (pf->set.sign)
			ft_elem(res, "-", start - 1, 1);
	}
	return (res);
}

char			*f_minus_handle(t_pf *pf, char *res, long double num)
{
	u_int64_t	dp;
	char		*ip_tmp;
	char		*dp_tmp;
	int			start;

	dp = cvt_num(pf, num);
	ip_tmp = ft_itoa_base_u((u_int64_t)num, 10);
	dp_tmp = ft_itoa_base_u(dp, 10);
	start = 1;
	if (!pf->set.sign && !pf->set.space && !pf->set.plus && !pf->set.zero)
		start = 0;
	else
		flaghandle(pf, res);
	ft_elem(res, ip_tmp, start, (int)ft_strlen(ip_tmp));
	start += (int)ft_strlen(ip_tmp);
	if (pf->set.hash || pf->set.precision || !pf->set.dot)
	{
		ft_elem(res, ".", start, 1);
		start++;
	}
	if (start < (int)ft_strlen(res))
		ft_elem(res, dp_tmp, start, ft_strlen(dp_tmp));
	return (res);
}
