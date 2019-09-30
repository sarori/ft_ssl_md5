/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:17:39 by sapark            #+#    #+#             */
/*   Updated: 2019/08/31 20:18:14 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_b(va_list *ap, t_pf *pf)
{
	u_int64_t	binary;
	char		*res;
	char		*tmp;
	int			len;

	binary = get_arg_uoxx(ap, pf);
	len = cal_len(pf, binary, 2);
	res = ft_memalloc_chr(len, ' ');
	if (pf->set.plus || pf->set.space)
		len -= 1;
	res[len] = '\0';
	if (binary == 0)
		res = di_zerohandle(pf, res, len);
	else
	{
		tmp = ft_itoa_base_u(binary, 2);
		res = b_helper(pf, res, tmp);
	}
	insertnode(pf, res);
	pf->res = ft_strjoinfree(pf->res, res, 1);
	free(res);
}

char	*b_zero(t_pf *pf, char *res, char *tmp)
{
	int	start;
	int	size;
	int	len;

	len = (int)ft_strlen(res);
	start = len - ft_strlen(tmp);
	size = pf->set.precision - (int)ft_strlen(tmp);
	size = pf->set.width > (int)ft_strlen(tmp) ?
	pf->set.width - (int)ft_strlen(tmp) : size;
	while (size-- > 0)
		res[--start] = '0';
	if (pf->set.hash)
		ft_elem(res, "0b", 0, 2);
	return (res);
}

char	*b_handle(t_pf *pf, char *res, char *tmp)
{
	int	start;
	int	len;
	int size;

	len = (int)ft_strlen(res);
	start = len - ft_strlen(tmp);
	size = pf->set.precision - (int)ft_strlen(tmp);
	ft_elem(res, tmp, start, (int)ft_strlen(tmp));
	if (pf->set.hash)
		ft_elem(res, "0b", start - 2, 2);
	if (pf->set.zero)
		res = b_zero(pf, res, tmp);
	if (!pf->set.zero)
	{
		size = pf->set.precision > (int)ft_strlen(tmp) ?
		pf->set.precision - (int)ft_strlen(tmp) : size;
		while (size-- > 0)
			res[--start] = '0';
	}
	return (res);
}

char	*b_helper(t_pf *pf, char *res, char *tmp)
{
	if (pf->set.minus)
	{
		if (pf->set.hash)
		{
			ft_elem(res, "0b", 0, 2);
			ft_elem(res, tmp, 2, (int)ft_strlen(tmp));
		}
		else
			ft_elem(res, tmp, 0, (int)ft_strlen(tmp));
	}
	else
		res = b_handle(pf, res, tmp);
	return (res);
}
