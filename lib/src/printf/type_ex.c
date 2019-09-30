/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:26:13 by sapark            #+#    #+#             */
/*   Updated: 2019/08/31 20:14:57 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*x_helper(t_pf *pf, char *res, char *tmp)
{
	if (pf->set.minus)
	{
		if (pf->set.hash)
		{
			ft_elem(res, "0x", 0, 2);
			ft_elem(res, tmp, 2, (int)ft_strlen(tmp));
		}
		else
			ft_elem(res, tmp, 0, (int)ft_strlen(tmp));
	}
	else
		res = x_handle(pf, res, tmp);
	return (res);
}

void	type_x(va_list *ap, t_pf *pf)
{
	u_int64_t	hex;
	char		*res;
	char		*tmp;
	int			len;

	hex = get_arg_uoxx(ap, pf);
	len = cal_len(pf, hex, 16);
	res = ft_memalloc_chr(len, ' ');
	if (pf->set.plus || pf->set.space)
		len -= 1;
	res[len] = '\0';
	if (hex == 0)
		res = di_zerohandle(pf, res, len);
	else
	{
		tmp = ft_itoa_base_u(hex, 16);
		res = x_helper(pf, res, tmp);
	}
	insertnode(pf, res);
	pf->res = ft_strjoinfree(pf->res, res, 1);
	free(res);
}

void	type_largex(va_list *ap, t_pf *pf)
{
	u_int64_t	hex_l;
	char		*res;
	char		*tmp;
	int			len;

	hex_l = get_arg_uoxx(ap, pf);
	len = cal_len(pf, hex_l, 16);
	res = ft_memalloc_chr(len, ' ');
	if (pf->set.plus || pf->set.space)
		len -= 1;
	res[len] = '\0';
	if (hex_l == 0)
		res = di_zerohandle(pf, res, len);
	else
	{
		tmp = ft_itoa_base_u(hex_l, 16);
		res = x_helper(pf, res, tmp);
	}
	res = ft_str_toupper(res);
	insertnode(pf, res);
	pf->res = ft_strjoinfree(pf->res, res, 1);
	free(res);
}

char	*xzero(t_pf *pf, char *res, char *tmp)
{
	int	start;
	int	size;
	int	len;

	size = pf->set.precision - (int)ft_strlen(tmp);
	len = (int)ft_strlen(res);
	start = len - ft_strlen(tmp);
	size = pf->set.width > (int)ft_strlen(tmp) ?
			pf->set.width - (int)ft_strlen(tmp) : size;
	while (size-- > 0)
		res[--start] = '0';
	if (pf->set.hash)
		ft_elem(res, "0x", 0, 2);
	return (res);
}

char	*x_handle(t_pf *pf, char *res, char *tmp)
{
	int	start;
	int	len;
	int size;

	len = (int)ft_strlen(res);
	start = len - ft_strlen(tmp);
	size = pf->set.precision - (int)ft_strlen(tmp);
	ft_elem(res, tmp, start, (int)ft_strlen(tmp));
	if (pf->set.hash)
		ft_elem(res, "0x", start - 2, 2);
	if (pf->set.zero)
		res = xzero(pf, res, tmp);
	if (!pf->set.zero)
	{
		size = pf->set.precision > (int)ft_strlen(tmp) ?
		pf->set.precision - (int)ft_strlen(tmp) : size;
		while (size-- > 0)
			res[--start] = '0';
	}
	return (res);
}
