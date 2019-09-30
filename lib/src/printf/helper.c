/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 02:45:55 by sapark            #+#    #+#             */
/*   Updated: 2019/09/07 02:46:33 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_elem(char *res, char *str, int start, int size)
{
	int	i;

	i = 0;
	while (size--)
		res[start++] = str[i++];
	return (res);
}

char	*element_join(char *res, char *s1, char *s2)
{
	unsigned int	len1;
	unsigned int	len2;

	if (!s1 || !s2)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	return (res);
}

int		cal_helper(t_pf *pf, u_int64_t num, int max, int base)
{
	if (ft_digit_base_u(num, base) == max && pf->set.hash)
	{
		if (base == 16)
			max++;
		max++;
	}
	if (max == ft_digit_base_u(num, base) && !pf->set.sign && base == 10)
	{
		if (pf->set.space || pf->set.plus)
			max += 1;
	}
	return (max);
}

int		cal_len(t_pf *pf, u_int64_t num, int base)
{
	int	max;

	max = 0;
	if (pf->set.width >= ft_digit_base_u(num, base) + (pf->set.sign ? 1 : 0))
	{
		if (pf->set.width >= pf->set.precision + (pf->set.sign ? 1 : 0))
			max = pf->set.width;
		else
			max = pf->set.precision + (pf->set.sign ? 1 : 0);
	}
	else
	{
		if (ft_digit_base_u(num, base) >= pf->set.precision)
			max = ft_digit_base_u(num, base) + (pf->set.sign ? 1 : 0);
		else
			max = pf->set.precision + (pf->set.sign ? 1 : 0);
	}
	max = cal_helper(pf, num, max, base);
	return (max);
}

void	type_len(va_list *ap, t_pf *pf)
{
	char	*s;
	char	*tmp;

	s = va_arg(*ap, char *);
	if (s == NULL)
		pf->res = ft_strjoinfree(pf->res, "0", 1);
	else
	{
		tmp = ft_itoa_base_u((uint64_t)ft_strlen(s), 10);
		pf->res = ft_strjoinfree(pf->res, tmp, 1);
		free(tmp);
	}
}
