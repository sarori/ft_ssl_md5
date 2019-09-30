/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_base_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:01:02 by sapark            #+#    #+#             */
/*   Updated: 2019/09/29 18:58:30 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digit_base_u(unsigned long long n, unsigned long long base)
{
	unsigned int	cnt;

	cnt = 0;
	while (n >= base)
	{
		n = n / base;
		cnt++;
	}
	return (cnt + 1);
}
