/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 01:56:45 by sapark            #+#    #+#             */
/*   Updated: 2019/09/07 03:51:32 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s_null(t_pf *pf, char *res)
{
	int len;

	len = ft_strlen(res);
	if (pf->set.minus)
		res = s_null_minus(pf, res);
	else
	{
		if (pf->set.dot)
		{
			if (pf->set.precision > len)
				ft_elem(res, "(null)", len - 6, 6);
			else
				ft_elem(res, "(null)",
					len - pf->set.precision, pf->set.precision);
		}
		else
			ft_elem(res, "(null)", len - 6, 6);
	}
	return (res);
}

char	*s_handle(t_pf *pf, char *res, char *str)
{
	if (!str)
		res = s_null(pf, res);
	else
	{
		if (!pf->set.width && !pf->set.dot)
			res = ft_strcpy(res, str);
		else
			res = (pf->set.dot && !pf->set.width) ?
				width_handle(pf, res, str) : prec_handle(pf, res, str);
	}
	return (res);
}

void	type_s(va_list *ap, t_pf *pf)
{
	char	*res;
	char	*str;
	int		len;

	str = va_arg(*ap, char *);
	if (!str && !pf->set.width && !pf->set.dot)
		pf->res = ft_strjoinfree(pf->res, "(null)", 1);
	else
	{
		len = cal_slen(pf, ft_strlen(str));
		res = ft_memalloc_chr(len, ' ');
		res[len] = '\0';
		res = s_handle(pf, res, str);
		insertnode(pf, res);
		pf->res = ft_strjoinfree(pf->res, res, 1);
		free(res);
	}
}

int		cal_slen_h(t_pf *pf, u_int64_t num, int tmp)
{
	int len;

	len = 0;
	if (pf->set.dot)
	{
		if (pf->set.width >= pf->set.precision)
			len = pf->set.width;
		else if (pf->set.width < pf->set.precision)
		{
			if (pf->set.precision <= tmp)
				len = pf->set.precision;
			else if (pf->set.precision > tmp)
			{
				if (pf->set.width > tmp)
					len = pf->set.width;
				else
					len = num == 0 ? 6 : (int)num;
			}
		}
	}
	return (len);
}

int		cal_slen(t_pf *pf, u_int64_t num)
{
	int	len;
	int	tmp;

	len = 0;
	tmp = num == 0 ? 6 : (int)num;
	if (num == 0 && !pf->set.width && !pf->set.dot)
		len = 6;
	else if (!pf->set.dot)
		len = pf->set.width > tmp ? pf->set.width : tmp;
	if (pf->set.dot)
		len = cal_slen_h(pf, num, tmp);
	return (len);
}
