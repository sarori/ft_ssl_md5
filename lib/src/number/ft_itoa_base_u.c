/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:06:03 by sapark            #+#    #+#             */
/*   Updated: 2019/09/24 20:06:20 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_u(unsigned long long value, unsigned long long base)
{
	char			*res;
	char			*str;
	unsigned int	size;
	int				i;

	str = "0123456789abcdef";
	res = NULL;
	if (base >= 2 && base <= 16)
	{
		size = (unsigned int)ft_digit_base_u(value, base);
		if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		i = size - 1;
		while (value >= base)
		{
			res[i--] = str[value % base];
			value /= base;
		}
		res[i] = str[value % base];
		res[size] = '\0';
	}
	return (res);
}
