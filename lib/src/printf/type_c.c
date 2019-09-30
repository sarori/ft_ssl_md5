/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 02:13:38 by sapark            #+#    #+#             */
/*   Updated: 2019/09/07 03:50:04 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_zerohandle(t_pf *pf, char *res, int len)
{
	int	start;

	start = pf->set.width > 1 ? pf->set.width - 1 : 1;
	if (pf->set.minus || pf->set.precision)
	{
		res[0] = '^';
		res[1] = '@';
		pf->minus += 1;
	}
	else
	{
		res[len - 2] = '^';
		res[len - 1] = '@';
		pf->minus += 1;
	}
	return (res);
}

void	type_c(va_list *ap, t_pf *pf)
{
	char	*res;
	int		i;
	int		len;
	int		start;

	i = (char)va_arg(*ap, int);
	len = pf->set.width >= 1 ? pf->set.width : 1;
	start = pf->set.width > 1 ? pf->set.width - 1 : 1;
	if (i == 0)
		len += 1;
	res = ft_memalloc_chr(len, ' ');
	res[len] = '\0';
	if (i == 0)
		res = c_zerohandle(pf, res, len);
	else
	{
		if (pf->set.minus)
			res[0] = i;
		else
			res[len - 1] = i;
	}
	insertnode(pf, res);
	pf->res = ft_strjoinfree(pf->res, res, 1);
	free(res);
}

char	*width_handle(t_pf *pf, char *res, char *str)
{
	int	size;
	int	i;

	i = 0;
	size = pf->set.precision >= (int)ft_strlen(str) ?
			ft_strlen(str) : pf->set.precision;
	while (size-- > 0)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*prec_handle(t_pf *pf, char *res, char *str)
{
	int	i;
	int	start;
	int	size;

	i = 0;
	if (pf->set.dot)
		size = pf->set.precision >= (int)ft_strlen(str) ?
			(int)ft_strlen(str) : pf->set.precision;
	else
		size = ft_strlen(str);
	if (pf->set.minus)
	{
		while (size-- > 0)
		{
			res[i] = str[i];
			i++;
		}
	}
	else
	{
		start = ft_strlen(res) - size;
		while (size-- > 0)
			res[start++] = str[i++];
	}
	return (res);
}

char	*s_null_minus(t_pf *pf, char *res)
{
	if (pf->set.minus)
	{
		if (pf->set.dot)
		{
			if (pf->set.precision > 0)
				ft_elem(res, "(null)", 0, pf->set.precision < 6 ?
					pf->set.precision : 6);
		}
		else
			ft_elem(res, "(null)", 0, 6);
	}
	return (res);
}
